
#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include <string.h>

#include <time.h>
#include "bubble_sort.h"
int main()
{
    int i;
    int j = 0;
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
    clock_inicio = clock();

    printf("Iniciando o programa: %ld\n", clock_inicio);

    for(j=0; j<n_linhas; j++){

    }

    clock_final = clock();

    printf("Final: %ld\n", clock_final);

    clock_total = (double)(clock_final - clock_inicio) / CLOCKS_PER_SEC;
    printf("Tempo_Total: %f\n", clock_total);

    // liberar_dados();
    liberar_dados(dados, n_linhas);

    //fclose(dados);
    return 0;
}
