#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "lista_enc.h"
#include "no.h"

struct pilhas {
    lista_enc_t *lista;
    //int topo;                       /*!< Índice do vetor que representa o topo da fila */
    //int data[TAMANHO_DADOS_PILHA]; /*!< Vetor que manterá os dados. */
};


/**
  * @brief  Cria uma nova pilha com TAMANHO_DADOS_PILHA inteiros
  * @param	Nenhum
  *
  * @retval pilha_t: ponteiro para uma nova pilha
  */
pilha_t * cria_pilha (void)
{
    pilha_t *pilha = (pilha_t*)malloc(sizeof(pilha_t));

    if(pilha == NULL){
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }
    pilha->lista = criar_lista_enc();

    return pilha;
}


/**
  * @brief  Empilha um novo inteiro.
  * @param dado: inteiro a ser adicionado no topo da pilha
  * @param pilha: pilha criada que receberá o dado.
  *
  * @retval Nenhum
  */
void push(void *dado, pilha_t *pilha)
{
    no_t *meu_no = criar_no(dado);
    add_cabeca(pilha->lista, meu_no);
}

/**
  * @brief Desempilha um inteiro.
  * @param pilha: pilha criada que retornará o dado.
  *
  * @retval int: valor inteiro do último dado empilhado.
  */
void * pop(pilha_t *pilha)
{

    if (lista_vazia(pilha->lista)) {
        fprintf(stderr, "pop() em pilha vazia!\n");
        return 0;
    }
    no_t *no = obter_cabeca(pilha->lista);

    void *dados = obter_dado(no);

    remove_cabeca(pilha->lista, no);
    free(no);
    return dados;
}
int pilha_vazia(pilha_t *pilha)
{
    return lista_vazia(pilha->lista);
}

void libera_pilha(pilha_t *pilha)
{
    free(pilha->lista);
    free(pilha);
}
int tamanho_pilha(pilha_t *pilha)
{

    int tam = tamanho_lista(pilha->lista);

    return tam;
}
