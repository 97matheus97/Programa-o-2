/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão:
  *         Series;Value;Time
  *         <int>;<float>;<string>
  *         <int>;<float>;<string>
  */

#include <stdio.h>
#include "dados.h"
#include "fila.h"
#include "lista_enc.h"


int main(){
    fila_t *fila = ler_dados_csv_fila("camera_temp.csv");
    /* Imprima os dados:*/
    imprime_fila(fila);

    liberar_dados(fila);
    libera_fila(fila);

    return 0;
}
