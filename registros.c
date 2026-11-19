#include "registros.h"
#include "util.h"


// Insere um pedido processado no inicio da lista encadeada
Historico *registrar_pedido_processado(Historico *cabeca, Pedido_entrega p){
    Historico *nova_cabeca = (Historico *) malloc(sizeof(Historico));
    verificar_alocacao(nova_cabeca);
    nova_cabeca->dados_pedidos = p;
    nova_cabeca->prox = cabeca;

    return nova_cabeca;

}

//Percorre toda a lista encadeada imprimindo os pedidos ja despachados
void consultar_historico(Historico *cabeca){
    if (cabeca == NULL){
        printf("Nao ha pedidos registrado no historico de despacho.\n");
    }else{
        while (cabeca != NULL){
            imprimir_historico(cabeca);
            cabeca = cabeca->prox;
        }
    }
}

// Realiza uma busca linear na lista pelo codigo de rastreamento
Historico *consultar_pedido_historico(Historico *cabeca, int cod_rastreio){
    while (cabeca != NULL || cabeca->dados_pedidos->cod_rastreio != cod_rastreio){
        cabeca = cabeca->prox;
    }

    if (cabeca == NULL){
        printf("Pedido nao registrado no historico de despacho.\n");
    }else{
        imprimir_historico(cabeca);
    }
}

void imprimir_historico(Historico *cabeca){
    printf("Codigo de rastreio: %d\n", cabeca->dados_pedidos->cod_rastreio);
    printf("Valor do pedido: %f\n", cabeca->dados_pedidos->valor);
    printf("Peso do pacote: %f\n", cabeca->dados_pedidos->peso_pacote);
    printf("Prioridade do pedido: %d\n", cabeca->dados_pedidos->prioridade);
}

// Varre a lista encadeada aplicando free() em todos os nos
void liberar_historico(Historico *cabeca){
    Historico *aux;
    while (cabeca != NULL) {
        aux = cabeca;
        cabeca = cabeca->prox;
        free(aux);
    }
}
