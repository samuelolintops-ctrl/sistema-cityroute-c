#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

void limpa_buffer();
void limpa_tela();
void espera_enter();
int solicita_int(char mensagem[], int min, int max);
float solicita_float(char mensagem[], int min, int max);
void le_string(char mensagem[], char variavel[], size_t tam);
int mostra_menu(char **lista_opcoes, int tam_list);

#endif // UTIL_H_INCLUDED
