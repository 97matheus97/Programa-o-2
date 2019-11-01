#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include <string.h>

struct dados
{
    int amostra;        /*!< Identificador numérido da amostra */
    float temperatura;  /*!< Valor do dado: temperatura */
    char tempo[64];      /*!< Time stamp */
};

dado_t * criar_dado (int amostra, float temperatura, char * tempo)
{

    dado_t * meu_novo_dado = malloc(sizeof(struct dados));

    meu_novo_dado->amostra = amostra;
    meu_novo_dado->temperatura = temperatura;
    //meu_novo_dado->tempo = tempo;
    // Colocar a criação dos dados aqui i

    strncpy(meu_novo_dado->tempo, tempo, 64);
    return meu_novo_dado;
}

dado_t **ler_dados_csv(char *camera_temp_cvs, int *n_linhas)
{
    char texto[64];
    int i = 0;
    int amostra;
    float temperatura;
    int linhas = 0;
    /* Demais Variáveis */

    dado_t **dados;

    FILE *fp = fopen("camera_temp.csv", "r");

    if (!fp)
    {
        perror("ler_dados_csv");
        exit(-1);
    }

    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Contar todas as linhas: use while e fgets() */
    while(fgets(texto, 64, fp) != NULL)    // lê a linha inteira
    {
        linhas++;
    }



    /* Aloque memória:
     * Agora é um vetor de ponteiros */
    dados = malloc(sizeof(struct dados *) * (linhas));

    if(dados == NULL){
        perror("Erro na main: ");
        exit(-1);
    }
    rewind(fp);
    /* Ignora primeira linha */
    fgets(texto,64, fp);


    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, texto) == 3)
    {
        printf("%d, %.1f, %s\n", amostra, temperatura, texto);

        /* Cria um novo dado abstrato e armazena a sua referência */
       dados[i] = criar_dado(amostra, temperatura, texto);
       //printf("lido: %d, %.1f, %s\n", amostra, temperatura, texto);
       i++;
    }

    *n_linhas = linhas;

    fclose(fp);
    return dados;
}

int imprime_amostra(dado_t * dados)
{
    return(dados->amostra);
}

float imprime_temperatura(dado_t * dados)
{
    return(dados->amostra);
}

char * imprime_tempo(dado_t * dados)
{
    return(dados->tempo);
}

void liberar_dados(dado_t **dados, int n_linhas)
{
    int i;
    for(i=0;i<n_linhas;i++)
    {
        free(dados[i]);
    }
    free(dados);
}

