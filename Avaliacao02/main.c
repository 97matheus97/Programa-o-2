/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjac�ncia, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void) {


	int i,j;
	grafo_t *g;

    /* Cria grafo com 13 v�rtices */
	g = cria_grafo(13);

	/* Criar adjac�ncias */
    // cria_adjacencia(g, 0, 1);  //Renan: criado apenas metade das arestas
    // cria_adjacencia(g, 0, 2);
    // cria_adjacencia(g, 0, 5);
    // cria_adjacencia(g, 1, 2);
    // cria_adjacencia(g, 1, 3);
    // cria_adjacencia(g, 2, 3);
    // cria_adjacencia(g, 2, 5);
    // cria_adjacencia(g, 3, 2);
    // cria_adjacencia(g, 3, 4);
    // cria_adjacencia(g, 4, 3);
    // cria_adjacencia(g, 4, 5);
    // cria_adjacencia(g, 5, 2);
    // cria_adjacencia(g, 5, 4);




    //Renan:
    cria_adjacencia(g, 0, 1);
	cria_adjacencia(g, 1, 0);

	cria_adjacencia(g, 0, 2);
	cria_adjacencia(g, 2, 0);

	cria_adjacencia(g, 0, 5);
	cria_adjacencia(g, 5, 0);

	cria_adjacencia(g, 1, 3);
	cria_adjacencia(g, 3, 1);

	cria_adjacencia(g, 1, 2);
	cria_adjacencia(g, 2, 1);

	cria_adjacencia(g, 2, 5);
	cria_adjacencia(g, 5, 2);

	cria_adjacencia(g, 5, 4);
	cria_adjacencia(g, 4, 5);

	cria_adjacencia(g, 3, 4);
	cria_adjacencia(g, 4, 3);

	cria_adjacencia(g, 6, 7);
	cria_adjacencia(g, 7, 6);

	cria_adjacencia(g, 7, 8);
	cria_adjacencia(g, 8, 7);

	cria_adjacencia(g, 9, 10);
	cria_adjacencia(g, 10, 9);

	cria_adjacencia(g, 9, 11);
	cria_adjacencia(g, 11, 9);

	cria_adjacencia(g, 10, 11);
	cria_adjacencia(g, 11, 10);



	/* Imprime matriz */
	for (i=0; i < 12; i++){
		for (j=0; j < 20; j++)
			printf("[%d] [%d] : %d\n", i,j, adjacente(g,i,j));
	}

	componentes_conexos(g);

    //bfs(g, i, j);

    print_res(g);//, i, j);
	export_grafo_dot("grafo.dot", g);

	libera_grafo(g);

	return EXIT_SUCCESS;
}
