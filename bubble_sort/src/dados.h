#ifndef DADO_H_INCLUDED

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int amostra, float temperatura, char * tempo);

dado_t **ler_dados_csv(char *camera_temp_cvs, int *n_linhas);

void liberar_dados(dado_t **dados, int n_linhas);

int imprime_amostra(dado_t * dados);

float imprime_temperatura(dado_t * dados);

char * imprime_tempo(dado_t * dados);

void bubble_sort(dado_t **dados, int n_linhas);

void swap(dado_t **dados, int i, int j);


/* Outras funções aqui: fazer os comentários */

#endif
