/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string>
  */

#include <stdio.h>
#include <stdlib.h>

#include "dados.h"
#include "lista_enc.h"
#include "no.h"


int main(){
    lista_enc_t *lista = ler_dados_csv("camera_temp.csv");

    /* Imprima os dados:*/
    imprime_dados(lista);

    liberar_dados(lista);

    return 0;
}
