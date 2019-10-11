#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"
#include "dados.h"

#define FALSO 0
#define VERDADEIRO 1

struct filas {
	lista_enc_t *lista;
};


//cria uma fila generica
fila_t * cria_fila (void)
{
    fila_t *fila = malloc(sizeof(fila_t));

    if (fila == NULL)
    {
        perror("cria_lista_enc:");
        exit(EXIT_FAILURE);
    }

    fila->lista = criar_lista_enc();

    return fila;
}


//adiciona elemento
void enqueue(void* dado, fila_t *fila)
{
    //no_t *meu_dado;
    no_t *meu_no  = criar_no(dado);
    add_cauda(fila->lista, meu_no);

}

//retira elemento do topo
void *dequeue(fila_t *fila)
{
    if (lista_vazia(fila->lista)){
		fprintf(stderr, "dequeue() em fila vazia!\n");
		return 0;
	}

	no_t* no = obter_cabeca(fila->lista);

	void* dado = obter_dado(no);
	remover_cabeca(fila->lista);
    free(no);
	return dado;
}

void libera_fila(fila_t *fila)
{
    free(fila->lista);
    free(fila);
}

int fila_vazia(fila_t *fila)
{
    return lista_vazia(fila->lista);
}
