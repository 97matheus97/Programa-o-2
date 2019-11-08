
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#include "bubble_sort.h"
#include "dados.h"


#define repetir 20

int main()
{
    int i;
    int j = 0;
    int n_linhas = 0;

    dado_t **dados;
    //int tempo;

    clock_t  clock_inicio = 0, clock_final = 0, clock_total = 0;

    //dado_t *dados
    //ler_dados_csv("camera_temp.csv", &n_linhas);

    //clock_inicio = clock();

    //bubble_sort(dados, n_linhas);
    printf("Iniciando o programa: %ld\n", clock_inicio);

    for(j = 0; j < repetir; j++){

    	for(i=0;i<n_linhas; i++){
    	dados[i] = rand() % n_linhas;
    	}

    	clock_inicio = clock();


    	clock_final = clock();

    	printf("Final: %ld\n", clock_final);

    	bubble_sort(dados, &n_linhas);
    	clock_total = (double)(clock_final - clock_inicio) / CLOCKS_PER_SEC;
    	printf("Tempo_Total: %g\n", clock_total);

    	srand(time(NULL));
    }
    // liberar_dados();
    liberar_dados(dados, n_linhas);

    //fclose(dados);
    return 0;
}
