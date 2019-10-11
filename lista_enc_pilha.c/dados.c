/* de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
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

    strncpy(meu_novo_dado->tempo, tempo, 64);
    return meu_novo_dado;

    // Colocar a criação dos dados aqui
    return meu_novo_dado;
}



pilha_t *ler_dados_csv_pilha(char *camera_temp_csv)
{
    char tempo[64];
    int amostra;
    float temperatura;
    /* Demais Variáveis */
    pilha_t *pilha;
    dado_t *dado;

    FILE *fp = fopen(camera_temp_csv,"r");

    if (!fp)
    {
        perror("ler_dados_csv");
        exit(-1);
    }

    pilha = cria_pilha();

    /* Ignora primeira linha */
    fgets(tempo,64, fp);

    /* Note que não e mais necessário contar as linhas */

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, tempo) == 3)
    {
        printf("Lido %d, %.1f, %s\n", amostra, temperatura, tempo);

        /* Cria um novo dado abstrato e armazena a sua referência */
        dado = criar_dado(amostra, temperatura, tempo);
        push(dado,pilha);

    }
    fclose(fp);
    return pilha;
}
void imprime_dados(pilha_t *pilha)
{

    //Imprima os dados:*/
    while (!pilha_vazia(pilha)){
      dado_t *meu_dado = pop(pilha);

      printf("%d, %.1f, %s\n", meu_dado->amostra, meu_dado->temperatura, meu_dado->tempo);
      free(meu_dado);
    }
}

void liberar_dados(pilha_t *pilha)
{

    dado_t *dado;
    while(!pilha_vazia(pilha)){
        dado = pop(pilha);
        free(dado);
    }
}


