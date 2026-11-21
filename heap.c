#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "modelos.h"

int pai(int i){
    return (i - 1) / 2;
}


int filho_esquerdo(int i){
    return 2 * i + 1;
}


int filho_direito(int i){
    return 2 * i + 2;
}


void heap_subir(Heap *heap, int i){

}


void heap_descer(Heap *heap, int i){

}


int tem_maior_prioridade(Pedido_entrega *a, Pedido_entrega *b){
    // Avalia as prioridades
    if(a->prioridade > b->prioridade) return 1;
    if(a->prioridade < b->prioridade) return 0;
    
    // Desempate FIFO
    if(a->ordem_chegada < b->ordem_chegada) return 1;
    else return 0;
}


void heap_troca(){
    
}


int heap_inicializa(Heap *h, int capacidade){
    h->dados = malloc(sizeof(Pedido_entrega) * capacidade);
    if(h->dados == NULL){
        return 0;
    }
    h->capacidade = capacidade;
    h->tamanho = 0;
    h->proximo_ordem = 0;
    return 1;
}


void heap_destroi(Heap *h){

}


int heap_insere(Heap *h, Pedido_entrega p){
    // Protecao para endereco invalido e para estouro de capacidade
    if(h == NULL || h->tamanho > h->capacidade){
        return 0;
    }

    // Confere se tem espaco suficiente alocado, se nao houver duplica a capacidade atual
    if(h->capacidade == h->tamanho){
        h->capacidade = h->capacidade * 2;
        h->dados = realloc(h->dados, h->capacidade);
        if(h->dados == NULL) return 0; // trocar para funcao de verificacao de memoria
    }

    /* Insere o elemento na proxima posicao disponivel
    Atribui a ordem de chegada ao pedido e atualiza o contador da ordem de chegada
    Coloca o pedido no vetor da heap e atualiza a qtd de elementos dela
    */
    p.ordem_chegada = h->proximo_ordem;
    h->proximo_ordem++;
    h->dados[h->tamanho] = p;
    h->tamanho++;

    // Logica heapfy-up
    while();
    return 1;
}


Pedido_entrega *heap_remove_prioritario(Heap *h){

}


Pedido_entrega *heap_consulta_prioritario(Heap *h){
    if(h->tamanho == 0){
        return NULL;
    }
    return h->dados;
}


void heap_exibir(Heap *h){

}


int heap_existe_destino(Heap *h, int id_destino){
    if(h->tamanho == 0){
        return 0;
    }
    for(int i = 0; i < h->tamanho; i++){
        if(h->dados[i].id_destino == id_destino){
            return 1;
        }
    }
    return 0;
}
