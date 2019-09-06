/*
 ============================================================================
 Name        : lista_enc.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_enc.h"
#include "no.h"

void imprimi_lista(lista_enc_t* lista);

int main()
{
    no_t* elemento = NULL;
    lista_enc_t* lista = NULL;

    char nome_1[] = "IFSC";
    char nome_2[] = "DAELN";
    char nome_3[] = "Eletronica";

    lista = criar_lista_enc();

    elemento = criar_no((void*)nome_3);
    add_cabeca(lista, elemento);

    elemento = criar_no((void*)nome_1);
    add_cabeca(lista, elemento);

    elemento = criar_no((void*)nome_2);
    add_cauda(lista, elemento);

    //elemento = criar_no((void*)nome_3);
   // add_cauda(lista, elemento);

    // Impress�o da lista: deve-se colocar no m�dulo correto, neste caso o main
    imprimi_lista(lista);
    //tamanho_lista(lista);
    printf("Tamanho: %d\n", tamanho_lista(lista));
    //remove_cabeca(lista, elemento);
    return 0;
}

void imprimi_lista(lista_enc_t* lista){

    no_t *meu_no = obter_cabeca(lista);

    while(meu_no){
        printf("Conteudo: %s\n", obter_dado(meu_no));
        meu_no = obter_proximo(meu_no);
        //printf("Tamanho: %d\n", tamanho_lista(lista));
    }
}
