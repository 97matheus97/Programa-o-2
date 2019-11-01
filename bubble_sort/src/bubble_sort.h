/*
 * bubble_sort.h
 *
 *  Created on: 29 de out de 2019
 *      Author: Mateus
 */

#include "dados.h"
#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

void bubble_sort(dado_t **dados, int elementos);

void swap(dado_t *dado, dado_t *dado);

void obter_tempo(int *v[]);

#endif /* BUBBLE_SORT_H_ */
