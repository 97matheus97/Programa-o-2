#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dados.h"
#include "lista_enc.h"
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
    //meu_novo_dado->tempo = tempo;
    // Colocar a criação dos dados aqui

    strncpy(meu_novo_dado->tempo, tempo, 64);
    return meu_novo_dado;
}

lista_enc_t *ler_dados_csv(char *camera_temp_cvs)
{
    char tempo[64];
    int amostra;
    float temperatura;

    /* Demais Variáveis */
    lista_enc_t *lista;
    dado_t *dado;
    no_t *meu_no;

    FILE *fp = fopen("camera_temp.csv", "r");

    if (!fp)
    {
        perror("ler_dados_csv");
        exit(-1);
    }

    fseek(fp, 10, SEEK_SET);

    lista = criar_lista_enc();
    /* Ignora primeira linha */
    fgets(tempo,64, fp);

    while (fscanf (fp, "%d,%f,%63[^\n]", &amostra, &temperatura, tempo) == 3)
    {
        //printf("%d, %.1f, %s\n", amostra, temperatura, tempo);

        /* Cria um novo dado abstrato e armazena a sua referência */
      dado = criar_dado(amostra, temperatura, tempo);
      meu_no = criar_no(dado);
      add_cauda(lista, meu_no);
    }

    fclose(fp);
    return lista;
}

void imprime_dados(lista_enc_t *lista)
{
    no_t *no = obter_cabeca(lista);
    while(no){
        dado_t *dados = obter_dado(no);
        printf("%d, %.1f, %s\n", dados->amostra, dados->temperatura, dados->tempo);
        no = obter_proximo(no);
    }

}
/*
int imprime_amostra(lista_enc_t *lista)
{

    return(lista->amostra);
}

float imprime_temperatura(lista_enc_t * lista)
{
    return(lista->amostra);
}

char * imprime_tempo(lista_enc_t *lista)
{
    return(lista->tempo);
}
*/
void liberar_dados(lista_enc_t *lista)
{
    no_t *no = obter_cabeca(lista);
    no_t *prox;

	while(no){
        free(obter_dado(no));
        prox = obter_proximo(no);
		free(no);
		no = prox;
	}
    free(lista);
}

