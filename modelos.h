#ifndef MODELOS_H_INCLUDED
#define MODELOS_H_INCLUDED

#define TAM_NOME_LOCAL 81

// Constantes para niveis de prioridade
typedef enum{
    PRIORIDADE_EXPRESSA = 3,
    PRIORIDADE_VIP = 2,
    PRIORIDADE_CONVENCIONAL = 1
} Prioridade;

// Representa um local de destino das encomendas
typedef struct ponto_entrega{
	int id_ponto;
	char nome_local[TAM_NOME_LOCAL];
	double latitude, longitude;
} Ponto_entrega;

// Representa a arvore BST para os pontos de entrega
typedef struct noBST{
    Ponto_entrega dados; 
    int altura; 
    struct noBST* esq;
    struct noBST* dir;
} NoBST;


// Representa um pacote a ser despachado
typedef struct pedido_entrega{
	int cod_rastreio;
	Prioridade prioridade;
	unsigned long ordem_chegada;
	float peso_pacote;
	int id_destino;
	float valor;
} Pedido_entrega;

// Histórico dos pedidos ja despachados
typedef struct historico{
    Pedido_entrega *dados_pedidos;
    struct historico *prox;
} Historico;

// Estrutura da fila de prioridade dos pedidos
typedef struct heap{
    Pedido_entrega *dados;
    int tamanho;
    int capacidade;
    unsigned long proximo_ordem;
} Heap;

#endif // MODELOS_H_INCLUDED
