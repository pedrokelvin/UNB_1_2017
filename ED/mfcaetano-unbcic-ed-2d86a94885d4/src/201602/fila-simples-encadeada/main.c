#include <stdio.h>
#include "fila.h"


int main(){

    t_fila* fila = aloca_fila();

    int i;
    
    insereNaFila(3, fila);
    insereNaFila(2, fila);
    insereNaFila(1, fila);
    insereNaFila(5, fila);

    imprime_fila(fila);

    for(i = 0; i < 5 ; i++)
        printf("%d \n", RemoveDaFila(fila));

    
    apaga_fila(fila);

    

    return 0;
}
