#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

/*
 * Funcao: limpa_tela
 * Complexidade Temporal: O(1) pior caso
 * Limpa a tela do terminal de forma portatil (Windows, Linux e Mac).
 */
void limpa_tela();

/*
 * Funcao: limpa_buffer
 * Complexidade Temporal: O(1) medio / O(n) pior caso (onde n e a quantidade de caracteres no buffer)
 * Limpa o buffer de entrada do teclado ate a quebra de linha ou EOF.
 */
void limpa_buffer();

/*
 * Funcao: espera_enter
 * Complexidade Temporal: O(1) pior caso
 * Pausa a execucao e aguarda o usuario pressionar ENTER para continuar.
 */
void espera_enter();

/*
 * Funcao: solicita_int
 * Complexidade Temporal: O(1) medio / O(k) pior caso (onde k e o numero de tentativas invalidas)
 * Captura e valida um numero inteiro dentro de um intervalo [min, max].
 */
int solicita_int(char mensagem[], int min, int max);

/*
 * Funcao: solicita_float
 * Complexidade Temporal: O(1) medio / O(k) pior caso (onde k e o numero de tentativas invalidas)
 * Captura e valida um numero real dentro de um intervalo [min, max].
 */
float solicita_float(char mensagem[], int min, int max);

/*
 * Funcao: le_string
 * Complexidade Temporal: O(n) pior caso (onde n e o tamanho maximo da string 'tam')
 * Exibe uma mensagem e le uma string da entrada padrao removendo o '\n'.
 */
void le_string(char mensagem[], char string[], size_t tam);

/*
 * Funcao: mostra_menu
 * Complexidade Temporal: O(n) pior caso (onde n e a quantidade de opcoes 'tam_list')
 * Exibe um menu enumerado na tela e retorna a opcao escolhida pelo usuario.
 */
int mostra_menu(char **lista_opcoes, int tam_list);


/*
 * Funcao: verificar_alocacao
 * Complexidade Temporal: O(1) pior caso
 * Verifica se o ponteiro passado como parametro é nulo, encerrando o programa caso a alocação tenha falhado.
 */
void verificar_alocacao(void *ptr);

#endif // UTIL_H_INCLUDED
