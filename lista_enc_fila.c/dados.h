#ifndef DADO_H_INCLUDED
#include "fila.h"
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

fila_t *ler_dados_csv_fila(char *camera_temp_csv);

void imprime_fila(fila_t *fila);

void liberar_dados(fila_t *fila);

/* Outras funções aqui: fazer os comentários */




#endif
