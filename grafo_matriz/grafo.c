/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "no.h"
#include "lista_enc.h"
#include "grafo.h"
#include "fila.h"
#include "pilha.h"

struct vertices{
	int id;         /*!< Identifica��o num�rica do v�rtice  */
	int pai;
	int dist;
	int visitado;
    /* Mais informa��es, se necess�rio */
};

struct arestas {
	int adj; /*!< Valor booleando. Verdadeiro representa uma adjac�ncia entre dois v�rtices  */
	int peso; /* peso da areta
	char nome[64] nome da aresta */

    /* Mais informa��es, se necess�rio */
};

struct grafos{
	int n_vertices;        /*!< N�mero de v�rtices do grafo  */
	vertice_t *vertices;   /*!< Vetor de ponteiros: conjunto V */
	aresta_t **matriz_adj;	/* Matriz de adjac�ncia: conjunto E */
	//lista_enc_t *vertices;
};


/**
  * @brief  Busca em largura: BFS
  * @param	grafo: um grafo representado por matriz adjac�ncia
  * @param	inicial: n�mero do v�rtice inicial da busca
  *
  * @retval Nenhum. Dados s�o disponibilizados nos v�rtices
  */
void bfs(grafo_t* g, int inicial){

	int v; // vertice
	int *u;
	fila_t* fila = cria_fila();

	for(v=0; v <g->n_vertices; v++){
		g->vertices[v].dist = -1;
		g->vertices[v].pai = -1;
		//g->vertices[v].id = NULL;
	}

	g->vertices[inicial].dist = 0;// Dist�ncia da fonte at� ela mesma � 0
	enqueue(&inicial, fila);    // adiciona o vertice inicial na cauda da fila

	while(!fila_vazia(fila)){
	 u = dequeue(fila);
		for(v=0; v<g->n_vertices; v++){
			if(adjacente(g, *u, v)){
				g->vertices[v].dist =  g->vertices[*u].dist + 1;
				g->vertices[v].pai = *u;
				int *j = malloc(sizeof(int));
				*j = v;
				enqueue(j, fila);
			}
		}if(u != &inicial)
		free(u);
	}
	libera_fila(fila);
}


/**
  * @brief  Busca em profundidade: DFS
  * @param	grafo: um grafo representado por matriz adjac�ncia
  * @param	inicial: n�mero do v�rtice inicial da busca
  *
  * @retval Nenhum. Dados s�o disponibilizados nos v�rtices
  */
void dfs(grafo_t *g, int inicial){

	int v, *u; // v,  *u ponteiro para vertices
	pilha_t *pilha = cria_pilha(); // cria_pilha

	for(v=0; v<g->n_vertices; v++){
		g->vertices[v].visitado = 0;
	}
	push(&inicial, pilha); // coloca na pilha

	while(!pilha_vazia(pilha)){
		u = pop(pilha);

		if(g->vertices[*u].visitado == 0){
			g->vertices[*u].visitado = 1;

			for(v=0; v<g->n_vertices; v++){
				if(adjacente(g, *u, v)){

					int *j = malloc(sizeof(int));
					*j = v;
					push(j, pilha);
				}
			}

		}if(u != &inicial)
		free(u);
	}
}

/**
  * @brief  Cria uma novo grafo est�tico
  * @param	vertices: quantidade de v�rtices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda n�mero total de v�rtices */
	g->n_vertices = vertices;
    /* Aloca v�rtices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de v�rtices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));

    /* Aloca 1a dimens�o da matriz de adjac�ncia */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	 /* Aloca 2a dimens�o da matriz de adjac�ncia */
	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

void print_matrix(grafo_t *g)
{
	int i, j;
	for (i=0; i <g->n_vertices; i++){
		for (j=i+1; j <g->n_vertices; j++)
			if(g->matriz_adj[i][j].adj == 1)
			printf("[%d] [%d]\n", i, j);
		}
}
void exportar_grafo(const char *nome, grafo_t *g)
{
	FILE *fp = fopen(nome, "w");
	if(fp == NULL){
		printf("Erro");
		exit(1);
	}

	fprintf(fp, "grafo G \n");

	int i, j;
	for(i=0; i < g->n_vertices; i++){
		for(j=0; j < g->n_vertices && j<=i; j++){
			if(adjacente(g, i, j)){
				fprintf(fp, "%d -- %d\n", i, j);
			}
		}
	}
	fclose(fp);
}
/**
  * @brief  Libera a mem�ria utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void print(grafo_t *g)
{
	 int i;

	 printf("PRINTING NODES\n");
	 for (i=0; i < g->n_vertices; i++)
	    printf("vertice: % d\tdist: % d\tpai: % d \tvisitado: % d\n", i, g->vertices[i].dist, g->vertices[i].pai, g->vertices[i].visitado);

}
void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

/**
  * @brief  Cria adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se adjac�ncia for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

/**
  * @brief  Remove adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se adjac�ncia for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

/**
  * @brief  Retorna adjac�ncia entre v�rtices u e v
  * @param	u: �ndice do v�rtice u
  * @param  v: �ndice do v�rtice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v){

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}
