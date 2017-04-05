#include <stdio.h>
#include "lista.h"


int main(){

    t_lista* lista = aloca_lista();
    
    insereInicio(3, lista);
    insereInicio(2, lista);
    insereInicio(1, lista);
    insereInicio(5, lista);

    insereFinal(6, lista);

    inserir(10, 20, lista);
    inserir(2, 30, lista);
    inserir(2, 40, lista);


    imprime_lista(lista);
    
    apaga_lista(lista);

    

    return 0;
}
