#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "modelos.h"

/*
Funcao: tem_maior_prioridade
Complexidade Temporal: 
Retorna 1 se 'a' sai antes de 'b' (prioridade, depois FIFO). O(1) 
*/
int tem_maior_prioridade(Pedido_entrega *a, Pedido_entrega *b);

/* 
Funcao: heap_inicializa
Complexidade Temporal: 
Aloca o vetor do heap. Retorna 1 em sucesso, 0 em falha. O(1) 
*/
int heap_inicializa(Heap *h, int capacidade);

/* 
Funcao: heap_destroi
Complexidade Temporal: O(1) 
Libera o vetor do heap.
*/
void heap_destroi(Heap *h);

/* 
Funcao: heap_insere
Complexidade Temporal: O(log n) amortizado 
Insere o pedido atribuindo ordem_chegada. Retorna 1/0. 
*/
int heap_insere(Heap *h, Pedido_entrega p);

/* 
Funcao: heap_remove_prioritario
Complexidade Temporal: O(log n)
Remove o prioritario e o devolve em *p. Retorna 0 se vazio. 
*/
int heap_remove_prioritario(Heap *h, Pedido_entrega *p);

/* 
Funcao: heap_consulta_prioritario
Complexidade Temporal: O(1)
Copia o prioritario para *p sem remover. Retorna 0 se vazio. 
*/
Pedido_entrega *heap_consulta_prioritario(Heap *h, Pedido_entrega *p);

/* 
Funcao: heap_exibir
Complexidade Temporal: O(n) 
Imprime os pendentes na ordem do vetor do heap.
*/
void heap_exibir(Heap *h);

/* 
Funcao: heap_existe_destino
Complexidade Temporal: O(n) 
Retorna 1 se ha pedido pendente para o destino (RF03.1).
*/
int heap_existe_destino(Heap *h, int id_destino);

#endif // HEAP_H_INCLUDED