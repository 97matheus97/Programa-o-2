
/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(void){



	grafo_t *g;

    /* Cria grafo com 8 vértices */
	g = cria_grafo(5);

	cria_adjacencia(g, 0, 1);
	cria_adjacencia(g, 1, 2);
	cria_adjacencia(g, 2, 3);
	cria_adjacencia(g, 2, 4);


	/* Imprime matriz */

	print_matrix(g);
	//print(g);

	bfs(g, 3);
	dfs(g, 3);

	print(g);
	//print(g);


	exportar_grafo("grafo.dot", g);
	libera_grafo(g);


	return EXIT_SUCCESS;
}
