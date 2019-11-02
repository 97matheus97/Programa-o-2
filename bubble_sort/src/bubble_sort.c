
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#include "bubble_sort.h"
#include "dados.h"

#define repeticoes 20
int main()
{
    int i;
    int j = 0;
    //int n_linhas = 0;


    //int tempo;

    clock_t clock_inicio = 0, clock_final = 0, clock_total = 0;

    //dado_t *dados = ler_dados_csv("camera_temp.csv", &n_linhas);

    dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

    /* Imprima os dados:*/
    for (i=0; i<n_linhas; i++)
    {
        //printf( "...", dados[i]->amostra, ... );
        printf("%d,%.1f,%s\n", imprime_amostra(dados[i]), imprime_temperatura(dados[i]), imprime_tempo(dados[i]));
    }

    clock_inicio = clock();

    //bubble_sort(dados, n_linhas);
    printf("Iniciando o programa: %ld\n", clock_inicio);

    for(j=0; j<repeticoes; j++){
    	dados[i] = rand() % n_linhas;
    }

    clock_final = clock();

    printf("Final: %ld\n", clock_final);

    clock_total = (double)(clock_final - clock_inicio) / CLOCKS_PER_SEC;
    printf("Tempo_Total: %f\n", clock_total);

    srand(time(NULL));
    // liberar_dados();
    liberar_dados(dados, n_linhas);

    //fclose(dados);
    return 0;
}
