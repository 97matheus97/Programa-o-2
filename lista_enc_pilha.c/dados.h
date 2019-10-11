#ifndef DADO_H_INCLUDED

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;
typedef struct pilhas pilha_t;
/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (int amostra, float temperatura, char * tempo);

pilha_t *ler_dados_csv_pilha(char *camera_temp_csv);
/* Outras funções aqui: fazer os comentários */
void liberar_dados(pilha_t *pilha);

void imprime_dados(pilha_t *pilha);


#endif
