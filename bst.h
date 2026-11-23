#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED


#include "modelos.h"

/*
* Funcao: cadastrar_ponto
* Complexidade Temporal: O(log n) medio / O(n) pior caso
* Retorna o ponteiro para o nó inicial da árvore (BST) de pontos de entregas. 
*/ 
NoBST* cadastrar_ponto(NoBST* raiz, int id_ponto, char nome_local[TAM_NOME_LOCAL], double latitude, double longitude); 

/*
* Funcao: buscar_ponto 
* Complexidade Temporal: O(log n) medio / O(n) pior caso
* Retorna o ponteiro para o nó do ponto de entrega. 
*/ 
NoBST* buscar_ponto (NoBST* raiz, int id_ponto); 


/*
* Funcao: listar_pontos
* Complexidade Temporal: O(n) 
* Retorna vazio (apenas imprime todos os elementos em ordem crescente - percurso em ordem).
*/ 
void listar_pontos (NoBST* raiz); 

/*
* Funcao: remover_ponto 
* Complexidade Temporal: O(log n) medio / O(n) pior caso
* Retorna o ponteiro para o nó inicial da árvore (BST) de pontos de entregas. 
*/ 
NoBST* remover_ponto(NoBST* raiz, int id_ponto); 

/*
* Funcao: minimo_ponto 
* Complexidade Temporal: O(log n) medio / O(n)  pior caso
* Retorna o ponteiro mais a esquerda de todos, ou seja, o com o menor id_ponto
*/ 
NoBST* minimo_ponto(NoBST* raiz);

/*
* Funcao: maximo_ponto 
* Complexidade Temporal: O(log n) medio / O(n)  pior caso
* Retorna o ponteiro mais a direita de todos, ou seja, o maior id_ponto
*/ 
NoBST* maximo_ponto(NoBST* raiz);

/*
* Funcao: liberar_arvore
* Complexidade Temporal: O(n) - percurso pos-ordem (post-order)
* retorna NULL para a raiz da arvore BST
*/ 
NoBST* liberar_arvore(NoBST* raiz); 


/*
* Funcao: balancear_NoBST 
* Complexidade Temporal: O(log n) medio / O(n)  pior caso
* Retorna o ponteiro para o nó inicial da árvore (AVL) de pontos de entregas.
*/ 
NoBST* balancear_NoBST(NoBST* raiz);

/*
* Funcao: altura 
* Complexidade Temporal: O(log n) medio / O(n)  pior caso
* Retorna altura da árvore (AVL) de pontos de entregas.
*/
int altura(NoBST* raiz);

/*
* Funcao: fator_de_Balanceamento
* Complexidade Temporal: O(log n) medio / O(n)  pior caso
* Retorna fator de balanceamento da árvore (AVL) de pontos de entregas.
*/
int fator_de_Balanceamento(NoBST* raiz);

/*
* Função: rotacao_esquerda
* Complexidade temporal: O(1)
* Retorna um ponteiro para a nova raiz da subárvore após a rotação.
 */
NoBST* rotacao_esquerda(NoBST* raiz);


/*
* Função: rotacao_direita
* Complexidade temporal: O(1)
* Retorna um ponteiro para a nova raiz da subárvore após a rotação.
 */
NoBST* rotacao_direita(NoBST* raiz);

#endif //  BST_H_INCLUDED


