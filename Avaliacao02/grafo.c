/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "fila.h"

struct vertices {
	int id;         /*!< Identifica��o num�rica do v�rtice  */
    int pai;
    int grupo;
    //int vertice;
    /* Mais informa��es, se necess�rio */






};

struct arestas {
	int adj;        /*!< Valor booleando. Verdadeiro representa uma adjac�ncia entre dois v�rtices  */

    /* Mais informa��es, se necess�rio */
};

struct grafos{
	int n_vertices;        /*!< N�mero de v�rtices do grafo  */
	vertice_t *vertices;   /*!< Vetor de ponteiros: conjunto V */
	aresta_t **matriz_adj;	/* Matriz de adjac�ncia: conjunto E */
};


void bfs(grafo_t *g, int vertice, int grupo);

void componentes_conexos(grafo_t *g){

    int id_grupo = 0;

    int v;

    for(v=0; v<g->n_vertices;v++){
        g->vertices[v].grupo = -1;
        g->vertices[v].pai = -1;//NULL;
    }

    for(v=0; v< g->n_vertices; v++){
        if(g->vertices[v].grupo == -1){
            bfs(g, v, id_grupo);
            id_grupo = id_grupo + 1;
        }
    }
}

void bfs(grafo_t *g, int vertice, int grupo){

    fila_t *fila = cria_fila();

    vertice_t *u;
    int v;
    ;
    g->vertices[vertice].grupo = grupo;
    enqueue(&g->vertices[vertice], fila);

    while(!fila_vazia(fila)){
        u = dequeue(fila);

        for(v=0; v< g->n_vertices; v++){
            //if(adjacente(g, v, u)){  //Renan: u é ponteiro, adjance é int!
            if(adjacente(g, u->id, v)){
                if(g->vertices[v].grupo == -1){// 1){
                    g->vertices[v].grupo = grupo;
                    g->vertices[v].pai = u->id;//Renan:u;
                    enqueue(&g->vertices[v], fila);
                }
            }
        }
    }
    libera_fila(fila);

}

//void print_res(grafo_t *g, int vertice, int grupo) Renan: Pq vertice e grupo aqui?
void print_res(grafo_t *g)
{

     int i;
     for (i=0; i < g->n_vertices; i++)
	    printf("[v]\n%d \t[grupo]:  %d", i, g->vertices[i].grupo);
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

    /* Inicializa ID */
    for ( i = 0; i < vertices; i++ ){
        g->vertices[i].id = i;
    }

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

/**
  * @brief  Libera a mem�ria utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
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

	if (u > g->n_vertices || v > g->n_vertices )
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

/**
  * @brief  Exporta o grafo (n�o direcionado) em formato dot
  * @param	filename: nome do arquivo
  * @param  g: um grafo
  *
  * @retval Nenhum
  */
void export_grafo_dot(const char *filename, grafo_t *g){
	int i,j;
	FILE *file;

	file = fopen(filename, "w");

	if (file == NULL){
		perror(__func__);
		exit(EXIT_FAILURE);
	}

	fprintf(file, "graph {\n");

	/* Exporta os v�rtices */
	for (i=0; i < g->n_vertices; i++){
		fprintf(file, "\t%d [label = \"%d (%d)\"]\n", i, i, i);
	}

	/* Exporta todas as arestas */
	for (i=0; i < g->n_vertices; i++){
		for (j=i; j < g->n_vertices;j++) {

			if (adjacente(g,i,j))
				fprintf(file, "\t%d -- %d\n", i, j);
		}
	}
	fprintf(file, "}\n");

	fclose(file);
}
