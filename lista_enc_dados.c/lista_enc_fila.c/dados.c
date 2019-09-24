
/* de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "dados.h"
#include "no.h"

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
    // Colocar a criação dos dados aqui

    strncpy(meu_novo_dado->tempo, tempo, 64);
    return meu_novo_dado;
}



fila_t *ler_dados_csv_fila(char *camera_temp_csv)
{
    char tempo[64];
    int amostra;
    float temperatura;
    /* Demais Variáveis */
    fila_t *fila;
    dado_t *dado;

    FILE *fp = fopen(camera_temp_csv,"r");

    if (!fp)
    {
        perror("ler_dados_csv");
        exit(-1);
    }

    fila = cria_fila();

    /* Ignora primeira linha */
    fgets(tempo,64, fp);

    /* Note que não e mais necessário contar as linhas */


    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, tempo) == 3)
    {
        printf("Lido %d, %.1f, %s\n", amostra, temperatura, tempo);

        /* Cria um novo dado abstrato e armazena a sua referência */
        dado = criar_dado(amostra, temperatura, tempo);
        enqueue(dado,fila);

    }

    fclose(fp);
    return fila;
}

void imprime_fila(fila_t *fila)
{
    while (!fila_vazia(fila)){
      dado_t *meu_dado = dequeue(fila);

      printf("%d, %.1f, %s\n", meu_dado->amostra, meu_dado->temperatura, meu_dado->tempo);
      free(meu_dado);
    }

}

void liberar_dados(fila_t *fila)
{
    dado_t *dado;
    while(!fila_vazia(fila)){
        dado = dequeue(fila);
        free(dado);
    }
}
