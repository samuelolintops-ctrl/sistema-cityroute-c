#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "modelos.h"
#include "heap.h"

int pai(int i){
    /*
    Retorna o indice do no pai de do elemento no indice i
    */
    return (i - 1) / 2;
}


int filho_esquerdo(int i){
    /*
    Retorna o indice do no filho esquerdo de do elemento no indice i
    */    
    return 2 * i + 1;
}


int filho_direito(int i){
    /*
    Retorna o indice do no filho direito de do elemento no indice i
    */
    return 2 * i + 2;
}


int tem_maior_prioridade(Pedido_entrega a, Pedido_entrega b){
    /*
    Funcao que avalia se o pedido a tem maior prioridade que o pedido b, 
    retornando 1 se sim e 0 se nao
    */
    // Avalia as prioridades
    if(a.prioridade < b.prioridade) return 1;
    if(a.prioridade > b.prioridade) return 0;
    
    // Desempate FIFO
    if(a.ordem_chegada < b.ordem_chegada) return 1;
    else return 0;
}


void heap_troca(Pedido_entrega *vetor_pedidos, int tam, int ind_a, int ind_b){
    /*
    Funcao que realiza a troca entre dois pedidos no vetor da heap com base nos 
    indices ind_a e ind_b
    */
    // Verfica se os indices sao validos
    if(ind_a < 0 || ind_b < 0 || ind_a >= tam || ind_b >= tam) return;
    // Realiza a troca
    Pedido_entrega aux = vetor_pedidos[ind_a];
    vetor_pedidos[ind_a] = vetor_pedidos[ind_b];
    vetor_pedidos[ind_b] = aux;
}


void heap_subir(Heap *pheap, int i){
    /*
    Funcao que realiza o procedimento heapify-up de uma heap a partir do indice
    i (o qual deve ser o indice do ultimo elemento do vetor da heap)
    */
    int pai_i;
    while(i > 0){ // Condicao para evitar mexer com indice que nao existe (menor que 0)
        pai_i = pai(i);
        if(tem_maior_prioridade(pheap->dados[i], pheap->dados[pai_i])){
            heap_troca(pheap->dados, pheap->tamanho, i, pai_i);
            i = pai_i; // Continua a verificacao na nova posicao
        }
        // Se a proprieadade esta satisfeita, quebra o loop
        else{
            break;
        }
    }
}


void heap_descer(Heap *pheap, int i){
    /*
    Funcao que realiza o procedimento heapify-down de uma heap a partir do 
    indice i (o qual, numa remocao, deve ser da cabeca da heap, ou seja, 0)
    */
    if(pheap->tamanho == 0){
        return;
    }
    int filho_esq, filho_dir, maior_filho;
    while(1){
        filho_esq = filho_esquerdo(i);
        filho_dir = filho_direito(i);
        // Se nem o filho esquerdo existe, i ja e uma folha
        if (filho_esq >= pheap->tamanho){
            break;
        }
        // Descobre qual dos filhos tem mais prioridade entre si
        maior_filho = filho_esq; // Assume o esquerdo como prioritario
        if(filho_dir < pheap->tamanho && tem_maior_prioridade(pheap->dados[filho_dir], pheap->dados[filho_esq])){
            maior_filho = filho_dir; // Se direito tem maior prioridade, o candidato vira o direito
        }
        // Verifica se o filho vencedor tem mais prioridade que o pai (i)
        if(tem_maior_prioridade(pheap->dados[maior_filho], pheap->dados[i])){
            heap_troca(pheap->dados, pheap->tamanho, i, maior_filho);
            i = maior_filho; // Continua a verificacao na nova posicao
        } 
        else{
            break; // O pai ja tem mais prioridade que ambos os filhos
        }
    }
}


int heap_inicializa(Heap *h, int capacidade){
    /*
    Inicializa uma heap, alocando um valor inicial para o vetor e zerando o 
    contador que controla a ordem de chegada e total de pedidos no vetor
    */
    h->dados = malloc(sizeof(Pedido_entrega) * capacidade);
    verificar_alocacao(h->dados);
    h->capacidade = capacidade;
    h->tamanho = 0;
    h->proximo_ordem = 0;
    return 1;
}


void heap_destroi(Heap *h){
    /*
    Libera a memoria de heap
    */
    // Protecao contra ponteiro nulo
    if(h == NULL) return;
    // Liberacao do vetor da heap
    if(h->dados != NULL){
        free(h->dados);
        h->dados = NULL;
    }
    free(h);
}


int heap_insere(Heap *h, Pedido_entrega p){
    /*
    Funcao que insere um novo elemento na fila
    */
    // Protecao para endereco invalido e para estouro de capacidade
    if(h == NULL || h->tamanho > h->capacidade){
        return 0;
    }
    // Confere se tem espaco suficiente alocado, se nao houver duplica a capacidade atual
    if(h->capacidade == h->tamanho){
        h->capacidade = h->capacidade * 2;
        h->dados = realloc(h->dados, sizeof(Pedido_entrega) * h->capacidade);
        verificar_alocacao(h->dados);
    }
    /* 
    Insere o elemento na proxima posicao disponivel
    Atribui a ordem de chegada ao pedido e atualiza o contador da ordem de chegada
    Coloca o pedido no vetor da heap e atualiza a qtd de elementos dela
    */
    p.ordem_chegada = h->proximo_ordem;
    h->proximo_ordem += 1;
    h->dados[h->tamanho] = p;
    h->tamanho += 1;
    // Logica de subida
    heap_subir(h, h->tamanho - 1);
    return 1;
}


int heap_remove_prioritario(Heap *h, Pedido_entrega *removido){
    /*
    Remove o elemento do inicio da fila (o prioritario)
    */
    // Protecao contra ponteiros nulos e fila vazia
    if(h == NULL || h->dados == NULL || h->tamanho == 0){
        return 0;
    }
    *removido = h->dados[0];
    if(h->tamanho == 1){
        h->tamanho -= 1;
    }
    else{
        h->dados[0] = h->dados[h->tamanho - 1];
        h->tamanho -= 1;
        heap_descer(h, 0);
    }
    return 1;
}


Pedido_entrega *heap_consulta_prioritario(Heap *h){
    /*
    Funcao que retorna o primeiro elemento da fila (o prioritario)
    */
    if(h == NULL || h->tamanho == 0){
        return NULL;
    }
    return h->dados;
}


void heap_exibir(Heap *h){
    /*
    Funcao que exibe na tela os pedidos pendentes na heap (exibe um vetor 
    desordenado contanto que o elemento na posicao 0 seja o prioritario)
    */
    if(h == NULL || h->dados == NULL || h->tamanho == 0){
        printf("\nPonteiro invalido ou fila de pedidos pendentes vazia.");
        espera_enter();
        return;
    }
    for(int i = 0; i < h->tamanho; i++){
        if(i == 0){
            printf("\n >> Pedido prioritario: <<");
        }
        printf("\nCodigo de rastreio: %d", h->dados[i].cod_rastreio);
        printf("\nPrioridade: ");
        if(h->dados[i].prioridade == PRIORIDADE_CONVENCIONAL) printf("CONVENCIONAL");
        else if(h->dados[i].prioridade == PRIORIDADE_EXPRESSA) printf("EXPRESSA");
        else if(h->dados[i].prioridade == PRIORIDADE_VIP) printf("VIP");
        printf("\nOrdem de chegada: %lu", h->dados[i].ordem_chegada);
        printf("\nPeso do pacote (kg): %f", h->dados[i].peso_pacote);
        printf("\nId do destino: %d", h->dados[i].id_destino);
        printf("\nValor: RS %.2f\n\n", h->dados[i].valor);
    }
    espera_enter();
    return;
}


int heap_existe_destino(Heap *h, int id_destino){
    /*
    Funcao que varre o vetor da fila em do id de destino dos pedidos
    retorna 1 se existe esse destino e 0 se nao
    */
    if(h == NULL || h->tamanho == 0){
        return 0;
    }
    for(int i = 0; i < h->tamanho; i++){
        if(h->dados[i].id_destino == id_destino){
            return 1;
        }
    }
    return 0;
}
