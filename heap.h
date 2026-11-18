#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "modelos.h"

/*
 * Funcao: tem_maior_prioridade
 * Complexidade Temporal: O(1) pior caso
 * Retorna 1 se 'a' sai antes de 'b' (prioridade, depois FIFO).
 */
int tem_maior_prioridade(Pedido_entrega *a, Pedido_entrega *b);

/* 
 * Funcao: heap_inicializa
 * Complexidade Temporal: O(1) pior caso
 * Aloca o vetor do heap. Retorna 1 em sucesso, 0 em falha.
 */
int heap_inicializa(Heap *h, int capacidade);

/* 
 * Funcao: heap_destroi
 * Complexidade Temporal: O(1) pior caso
 * Libera o vetor do heap.
 */
void heap_destroi(Heap *h);

/* 
 * Funcao: heap_insere
 * Complexidade Temporal: O(log n) pior caso
 * Insere o pedido atribuindo ordem_chegada. Retorna 1 em sucesso, 0 em falha.
 */
int heap_insere(Heap *h, Pedido_entrega p);

/* 
 * Funcao: heap_remove_prioritario
 * Complexidade Temporal: O(log n) pior caso
 * Retorna o pedido prioritario removido. Retorna NULL se a fila estiver vazia. 
 */
Pedido_entrega *heap_remove_prioritario(Heap *h);

/* 
 * Funcao: heap_consulta_prioritario
 * Complexidade Temporal: O(1) pior caso
 * Retorna o pedido prioritario sem remover. Retorna NULL se a fila estiver vazia. 
 */
Pedido_entrega *heap_consulta_prioritario(Heap *h);

/* 
 * Funcao: heap_exibir
 * Complexidade Temporal: O(n) pior caso
 * Imprime os pendentes na ordem do vetor do heap.
 */
void heap_exibir(Heap *h);

/* 
 * Funcao: heap_existe_destino
 * Complexidade Temporal: O(n) pior caso
 * Retorna 1 se ha pedido pendente para o destino.
 */
int heap_existe_destino(Heap *h, int id_destino);

#endif // HEAP_H_INCLUDED