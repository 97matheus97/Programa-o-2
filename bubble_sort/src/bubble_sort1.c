/*
 * bubble_sort1.c
 *
 *  Created on: 29 de out de 2019
 *      Author: Mateus
 */
#include "stdio.h"
#include "stdlib.h"

#include "bubble_sort.h"
#include "dados.h"


void bubble_sort(dado_t **dados, int n_linhas)
{
	int i;
	int j;

	for(i = n_linhas; i > 1; i--){
		for(j = 0; j < i - 1; j++){
			if(dados[j]->temperatura > dados[j + 1]->temperatura){
			   swap(dados, j, j + 1);
			}
		}
	}
}
void swap(dado_t **dados, int i, int j)
{

	dado_t *temp = dados[i];  // ??????
	dados[i] = dados[j];
	dados[j] = temp;
}

/*void insert_sort_direta(dado_t **dados, int elementos)
{
	int i, j;

	for(i=1; i<elementos; i++){
		for(j=1;j>0 && dados[j-1] > dados[j]; j--){
			swap(&dados[j], &dados[j-1]);
		}
	}
}

*/
