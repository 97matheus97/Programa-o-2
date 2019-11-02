
#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include <string.h>

#include <time.h>
#include <bubble_sort.h>
int main()
{
    int i;
    int n_linhas = 0;
    int tempo;
    int clock_inicio, clock_final, clock_total;

    //dado_t *dados = ler_dados_csv("camera_temp.csv", &n_linhas);
    dado_t **dados = ler_dados_csv("camera_temp.csv", &n_linhas);

    /* Imprima os dados:*/
    for (i=0; i<n_linhas; i++)
    {
        //printf( "...", dados[i]->amostra, ... );
        printf("%d,%.1f,%s\n", imprime_amostra(dados[i]), imprime_temperatura(dados[i]), imprime_tempo(dados[i]));
    }

    clock_1 = obter_tempo();

    bubble_sort();

    clock_2 = obter_tempo();

    tempo = clock_2 - clock_1;


    // liberar_dados();
    liberar_dados(dados, n_linhas);

    //fclose(dados);
    return 0;
}
