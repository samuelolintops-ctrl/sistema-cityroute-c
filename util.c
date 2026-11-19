#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void limpa_tela(){
    /*
    Funcao de limpar a tela do terminal. Portatil para Windows, Linux e Mac.
    */
    #ifdef _WIN32 // Windows
        system("cls");
    #else // Linux e Mac
        system("clear");
    #endif
}

void limpa_buffer(){
    /*
    Funcao que limpa o buffer do teclado. Alternativa para o fflush.
    */
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void espera_enter(){
    /*
    Funcao para travar a tela e esperar confirmacao do usuario para prosseguir.
    */
    printf("\nPressione \033[33mENTER\033[m para continuar...");
    getchar();
}

int solicita_int(char mensagem[], int min, int max){
    /*
    Funcao que captura um inteiro valido dentro de um intervalo especificado 
    (minimo e  maximo estao incluidos nesse intervalo).
    param mensagem: mensagem de comando para o usuario.
    param min: valor minimo que a funcao valida.
    param max: valor maximo que a funcao valida.
    return: valor validado
    */
    int n, valido;
    while(1){
        printf("%s", mensagem);
        valido = scanf("%d", &n);
        limpa_buffer();
        if(valido == 1 && n >= min && n <= max) break;
        printf("\nValor inválido! Digite novamente.");
        espera_enter();
    }
    return n;
}

float solicita_float(char mensagem[], int min, int max){
    /*
    Funcao que captura um numero real valido dentro de um intervalo especificado 
    (minimo e  maximo estao incluidos nesse intervalo).
    param mensagem: mensagem de comando para o usuario.
    param min: valor minimo que a funcao valida.
    param max: valor maximo que a funcao valida.
    return: valor validado
    */
    float n;
    int valido;
    while(1){
        printf("\n%s", mensagem);
        valido = scanf("%f", &n);
        limpa_buffer();
        if(valido == 1 && n >= min && n <= max) break;
        printf("\nValor invalido! Digite novamente.");
        espera_enter();
    }
    return n;
}

void le_string(char mensagem[], char string[], size_t tam){
    /*
    Funcao que exibe um comando ao usuario e captura uma string digitada pelo usuario.
    param mensagem: string comando ao usuario.
    param string: vetor a ser manipulado.
    param tam: tamanho do vetor de char de 'string'.
    */
    printf("\n%s", mensagem);
    if(fgets(string, tam, stdin) != NULL){
        string[strcspn(string, "\n")] = '\0';
    }
}

int mostra_menu(char **lista_opcoes, int tam_list){
    /*
    Funcao para exibir um menu na tela enumerado.
    param lista_opcoes: lista com as opcoes do menu.
    param tam_list: quantidade de itens na lista.
    return: retorna um int definindo a opcao digitada pelo usuario.
    */
    int opc;
    for(int i = 0; i < tam_list; i++){
        printf("\n%d. %s", i + 1, lista_opcoes[i]);
    }
    opc = solicita_int("\nDigite sua opcao: ", 0, tam_list - 1);
    return opc;
}

// Verifica se o ponteiro passado como parametro é nulo, encerrando o programa caso a alocação tenha falhado
void verificar_alocacao(void *ptr){
    if(ptr == NULL){
        printf("ERRO: Memoria nao alocada.\nPrograma encerrado");
        exit(1);
    }
}
