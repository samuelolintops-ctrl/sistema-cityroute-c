#ifndef REGISTROS_H_INCLUDED
#define REGISTROS_H_INCLUDED

#include "modelos.h"

/*
- Funcao: registrar_pedido_processado 
- Complexidade Temporal: O(1) pior caso
- Insere um pedido processado no inicio da lista encadeada.
 */
Historico *registrar_pedido_processado(Historico *cabeca, Pedido p);

/*
- Funcao: consultar_historico
- Complexidade Temporal: O(n) pior caso
- Percorre toda a lista encadeada imprimindo os pedidos ja despachados.
 */
void consultar_historico(Historico *cabeca);

/*
- Funcao: consultar_pedido_historico
- Complexidade Temporal: O(n) pior caso
- Realiza uma busca linear na lista pelo codigo de rastreamento.
 */
Historico *consultar_pedido_historico(Historico *cabeca, int cod_rastreio);

/*
- Funcao: liberar_historico
- Complexidade Temporal: O(n) pior caso
- Varre a lista encadeada aplicando free() em todos os nós.
 */
void liberar_historico(Historico *cabeca);

/*
- Funcao: imprimir_historico
- Complexidade Temporal: O(1) pior caso
- Imprime os detalhes (rastreio, valor, peso e prioridade) de um unico pedido processado recebido por parametro.
 */
void imprimir_historico(Historico *cabeca);

#endif 