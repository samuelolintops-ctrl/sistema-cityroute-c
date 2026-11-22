#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "modelos.h"


/*
 * Funcao: pai
 * Complexidade Temporal: O(1) pior caso
 * Retorna o indice do no pai do elemento passado.
 */
int pai(int i);

/*
 * Funcao: filho_esquerdo
 * Complexidade Temporal: O(1) pior caso
 * Retorna o indice do filho esquerdo do elemento passado.
 */
int filho_esquerdo(int i);

/*
 * Funcao: filho_direito
 * Complexidade Temporal: O(1) pior caso
 * Retorna o indice do filho direito do elemento passado.
 */
int filho_direito(int i);

/*
 * Funcao: tem_maior_prioridade
 * Complexidade Temporal: O(1) pior caso
 * Retorna 1 se 'a' sai antes de 'b' (prioridade, depois FIFO), 0 caso contrario.
 */
int tem_maior_prioridade(Pedido_entrega a, Pedido_entrega b);

/*
 * Funcao: heap_troca
 * Complexidade Temporal: O(1) pior caso
 * Realiza a troca entre dois pedidos no vetor da heap com base nos indices ind_a e ind_b.
 */
void heap_troca(Pedido_entrega *vetor_pedidos, int tam, int ind_a, int ind_b);

/*
 * Funcao: heap_subir
 * Complexidade Temporal: O(log n) pior caso
 * Realiza o procedimento heapify-up na heap a partir do indice i.
 */
void heap_subir(Heap *pheap, int i);

/*
 * Funcao: heap_descer
 * Complexidade Temporal: O(log n) pior caso
 * Realiza o procedimento heapify-down na heap a partir do indice i.
 */
void heap_descer(Heap *pheap, int i);

/*
 * Funcao: heap_inicializa
 * Complexidade Temporal: O(1) pior caso
 * Aloca o vetor da heap. Retorna 1 em sucesso, 0 em falha.
 */
int heap_inicializa(Heap *h, int capacidade);

/*
 * Funcao: heap_destroi
 * Complexidade Temporal: O(1) pior caso
 * Libera toda a memoria alocada dinamicamente pela heap.
 */
void heap_destroi(Heap *h);

/*
 * Funcao: heap_insere
 * Complexidade Temporal: O(n) pior caso (devido ao realloc) / O(log n) medio
 * Insere um novo pedido na fila mantendo a propriedade da heap. Retorna 1 em sucesso, 0 em falha.
 */
int heap_insere(Heap *h, Pedido_entrega p);

/*
 * Funcao: heap_remove_prioritario
 * Complexidade Temporal: O(log n) pior caso
 * Remove o elemento prioritario (raiz) e copia para 'removido'. Retorna 1 em sucesso, 0 em falha.
 */
int heap_remove_prioritario(Heap *h, Pedido_entrega *removido);

/*
 * Funcao: heap_consulta_prioritario
 * Complexidade Temporal: O(1) pior caso
 * Retorna o ponteiro para o primeiro elemento da fila (prioritario), ou NULL se vazia.
 */
Pedido_entrega *heap_consulta_prioritario(Heap *h);

/*
 * Funcao: heap_exibir
 * Complexidade Temporal: O(n) pior caso
 * Exibe na tela todos os pedidos pendentes na ordem estrutural do vetor da heap.
 */
void heap_exibir(Heap *h);

/*
 * Funcao: heap_existe_destino
 * Complexidade Temporal: O(n) pior caso
 * Varre o vetor da fila buscando o id_destino. Retorna 1 se existe, 0 caso contrario.
 */
int heap_existe_destino(Heap *h, int id_destino);

#endif // HEAP_H_INCLUDED