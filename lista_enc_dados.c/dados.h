#ifndef DADO_H_INCLUDED


/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;
typedef struct listas_enc lista_enc_t;
/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado(int amostra, float temperatura, char * tempo);

lista_enc_t *ler_dados_csv(char *camera_temp_cvs);

void imprime_dados(lista_enc_t *lista);

void liberar_dados(lista_enc_t *lista);

//int imprime_amostra(lista_enc_t *lista);

//float imprime_temperatura(lista_enc_t *lista);

//char * imprime_tempo(lista_enc_t *lista);




/* Outras funções aqui: fazer os comentários */

#endif

