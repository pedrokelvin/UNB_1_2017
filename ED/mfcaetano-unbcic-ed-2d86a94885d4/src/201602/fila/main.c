#include "filha.h"
#include <stdio.h>

int main(){
    t_fila* fila = getFila(10);
    int i = 0;

    for(i = 0; i < 9; i++)
        inserirFila(fila, i+1);

    //imprimirFila(fila);

    for(i = 0; i < 9; i++)
        printf("item removido: %d \n",  removerFila(fila));

    for(i = 10; i < 19; i++)
        inserirFila(fila, i+1);

    //imprimirFila(fila);

    for(i = 0; i < 9; i++)
        printf("item removido: %d \n",  removerFila(fila));


    liberaFila(fila);
}
