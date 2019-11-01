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


void bubble_sort(dado_t **dados, int elementos)
{
	int i;
	int j;


	for(i = elementos; i > 1; i--){
		for(j = 0; j < i - 1; j++){
			if(dados[j]->temperatura > dados[j + 1]->temperatura)
				swap(&dados[j], &dados[j + 1]);
		}
	}

}
void swap(dado_t *dados, dado_t *dados)
{

	int aux;

	aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}

void obter_tempo(int *v[])
{

}


