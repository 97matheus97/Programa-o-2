#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dado_t
{
    int amostra;
    float temperatura;
    char data[64];

};
int main(void)
{
    //int amostra;
    //char data[64];
    //float temperatura;
    int i=0;
    int n_linhas = 0;
    char info[64];


    // Ponteiro para alocação dinâmica dos dados
    struct dado_t *dados = NULL;

    FILE *fp = fopen("camera_temp.csv", "r");
    if(!fp)
    {
        perror("máximo");
        exit(1);
    }

    /* ignora a primeira linha */
    fgets(info, 64, fp);

    // contar o número de linhas do arquivo
    while(fgets(info, 64, fp) != NULL)    // lê a linha inteira
    {
        n_linhas++;
    }
    printf("linhas: %d", n_linhas);

    dados = malloc(sizeof(struct dado_t) * n_linhas);
    if(dados == NULL)
    {
        perror("main: ");
        exit(-1);
    }

    rewind(fp);

    //fgets(info, 64, arq_entrada);
    fgets(info, 64, fp); // ignora a primeira linha
    while(fscanf(fp, "%d,%f,%63[^\n]", &dados[i].amostra, &dados[i].temperatura, dados[i].data) == 3)
    {
        i++;
    }
    // dados[i].amostra = amostra;
    //imprime dados
    for(i=0; i<n_linhas; i++)
    {
        printf("\n%d,%.1f,%s", dados[i].amostra, dados[i].temperatura, dados[i].data);
    }


    free(dados);

    fclose(fp);

    return 0;
}
