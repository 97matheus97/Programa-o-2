
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "dados.h"
#include "lista_enc.h"


int main()
{
     pilha_t *pilha = ler_dados_csv_pilha("camera_temp.csv");
    //imprime_dados_pilha(pilha->lista);
    imprime_dados(pilha);

    liberar_dados(pilha);
    libera_pilha(pilha);
    return 0;
}
