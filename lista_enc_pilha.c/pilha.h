#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define TAMANHO_DADOS_PILHA 100

typedef struct pilhas pilha_t;

/**
  * @brief  Cria uma nova pilha com TAMANHO_DADOS_PILHA inteiros
  * @param	Nenhum
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t * cria_pilha (void);

int n_elemento(pilha_t *pilha);
/**
  * @brief  Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da pilha
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(void *dado, pilha_t *pilha);

/**
  * @brief Desempilha um inteiro.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
void * pop(pilha_t *pilha);

int pilha_vazia(pilha_t *pilha);

int tamanho_pilha(pilha_t *pilha);

void libera_pilha(pilha_t *pilha);
#endif // PILHA_H_INCLUDED
