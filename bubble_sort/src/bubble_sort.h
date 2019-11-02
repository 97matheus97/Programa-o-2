/*
 * bubble_sort.h
 *
 *  Created on: 29 de out de 2019
 *      Author: Mateus
 */

#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#include "dados.h"

void bubble_sort(dado_t **dados, int elementos);

void swap(dado_t *dados, dado_t *dados);

clock_t clock(void);
#endif /* BUBBLE_SORT_H_ */
