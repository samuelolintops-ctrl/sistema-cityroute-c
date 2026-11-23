#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "modelos.h"


NoBST* cadastrar_ponto(NoBST* raiz, int id_ponto, char nome_local[TAM_NOME_LOCAL], double latitude, double longitude){
    /*
    Funcao que insere um novo elemento na arvore verificando se já existe na arvore e puza o balanceamento
    */
   
    // id_ponto deve ser gerado e passado pela main, então, por exemplo: 1,2,3,...
    // caso a arvore esteja vazia
     if (raiz == NULL) {
        NoBST* novo = (NoBST*) malloc(sizeof(NoBST));
        verificar_alocacao(novo);

        novo->dados.id_ponto = id_ponto;
        strncpy(novo->dados.nome_local, nome_local, TAM_NOME_LOCAL - 1);
        novo->dados.nome_local[TAM_NOME_LOCAL - 1] = '\0'; // Garante o fim da string
        novo->dados.latitude = latitude;
        novo->dados.longitude = longitude;

        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
}

//  procura na arvore se ja existe um nó com esse id_ponto que quer cadastrar 
    if (id_ponto < raiz->dados.id_ponto) {
        raiz->esq = cadastrar_ponto(raiz->esq, id_ponto, nome_local, latitude, longitude);
    } else if (id_ponto > raiz->dados.id_ponto) {
        raiz->dir = cadastrar_ponto(raiz->dir, id_ponto, nome_local, latitude, longitude);
    } else {
        // Caso o ID ja exista na arvore
        printf("Aviso: Ponto com ID %d ja cadastrado.\n", id_ponto);
        return raiz;
    }

    // se depois que foi adcionado, ele vai avaliar possivel balanceamento
    return balancear_NoBST(raiz); // ele por fim vai retornar a raiz, então vai dá certo
}



NoBST* buscar_ponto (NoBST* raiz, int id_ponto){
    /*
    Função que busca o nó na árvore atraves do id_ponto passado
     */
     if (raiz == NULL) {
        return NULL;
    }

    if (id_ponto == raiz->dados.id_ponto) {
        return raiz;
    }

    //Recursao que vai dividindo a arvore e descartando metade sempre
    if (id_ponto < raiz->dados.id_ponto) {
        return buscar_ponto(raiz->esq, id_ponto); 
    } else {
        return buscar_ponto(raiz->dir, id_ponto);
    }
}



void listar_pontos (NoBST* raiz){
    /*

     */

}


NoBST* remover_ponto(NoBST* raiz, int id_ponto){
    /*

     */

}


NoBST* minimo_ponto(NoBST* raiz){
    /*

     */

}


NoBST* maximo_ponto(NoBST* raiz){
    /*

     */

}


int altura(NoBST* raiz){
    /*
    
    */

}


int fator_de_Balanceamento(NoBST* raiz){
    /*

    */

}


NoBST* rotacao_esquerda(NoBST* raiz){
    /*

     */

}


NoBST* rotacao_direita(NoBST* raiz){
    /*

     */

}
NoBST* balancear_NoBST(NoBST* raiz){
    /*

     */

}


NoBST* liberar_arvore(NoBST* raiz){
    /*

     */

}
