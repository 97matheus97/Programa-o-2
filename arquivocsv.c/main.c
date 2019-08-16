#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int amostra;
    char data[64];
    float temperatura;
    FILE *arq;
    arq = fopen("camera_temp.csv", "r");
    if(!arq)
    {
        perror("máximo");
        exit(-1);
    }

    //fgets(info, 64, arq_entrada);
    fgets(data, 63, arq);
    while(fscanf(arq, "%d,%f,%63[^\n]", &amostra, &temperatura, data) == 3)
    {
        printf("%d,%.1f,%s\n", amostra, temperatura, data);
    }


    fclose(arq);

    return 0;
}
