
#include "fila.h"
#include <stdlib.h>
#include <stdio.h>



/*----------------------------------------------------------*/
void insereNaFila(int valor, t_fila * fila){

    t_elemento* elemento = (t_elemento *)  malloc(sizeof(t_elemento));
    elemento->dado       = valor;
    elemento->proximo    = NULL;

    if( fila->primeiro == NULL ){
        fila->primeiro = elemento;
    }else{
        fila->ultimo->proximo = elemento;
    }

    fila->ultimo = elemento;
}/*end insereFinal()*/




int RemoveDaFila(t_fila * fila){

    t_elemento* elemento = fila->primeiro;
    int resultado;
    
    if( elemento == NULL ){
        printf("Fila estah vazia!\n");
        free(fila);
        exit(1);
    }

    resultado = elemento->dado;

    fila->primeiro = fila->primeiro->proximo;
    free(elemento);

    return resultado;
}



/*----------------------------------------------------------*/
void apaga_fila(t_fila* fila){
    t_elemento* ptr = fila->primeiro;

    while( ptr != NULL ){
        fila->primeiro = fila->primeiro->proximo;

        free(ptr);

        ptr = fila->primeiro;
    }

    free(fila);
}


/*----------------------------------------------------------*/
t_fila* aloca_fila(){
    t_fila* fila  =  (t_fila *)  malloc(sizeof(t_fila));
    fila->primeiro = NULL;
    fila->ultimo   = NULL;

    return fila;
}/*end aloca_fila()*/


/*----------------------------------------------------------*/
void imprime_fila( t_fila* fila){
    t_elemento* ptr = fila->primeiro;

    if(ptr == NULL){
        printf("fila VAZIA\n");
        return;
    }

    for(ptr = fila->primeiro; ptr != NULL; ptr = ptr->proximo){
        printf("%d", ptr->dado);

        if(ptr->proximo != NULL)
            printf(" -> ");

    }

    printf("\n");


}/*end imprime_fila()*/




