#include "filha.h"

#include <stdlib.h>
#include <stdio.h>



//---------------------------------------------
void inserirFila(t_fila* fila, int valor){

    if( fila->fim == fila->tamanho - 1){
        fila->fim = 0;
    }else{
        fila->fim++;
    }

    /*Testa estou de fila*/
    if( fila->fim == fila->inicio ){
        printf("Ocorreu um overflow de fila \n");
        exit(1);
    }

    fila->item[fila->fim] = valor;

}//end inserirFila()


//---------------------------------------------
int filaVazia(t_fila* fila){
    return (fila->inicio == fila->fim);
}


//---------------------------------------------
int removerFila(t_fila* fila){

    if( filaVazia(fila) ){
        printf("Underflow na fila! \n");
        exit(1);
    }

    /*passou do limite do vetor*/
    if(fila->inicio == fila->tamanho - 1){
        fila->inicio = 0;
    }else{
        fila->inicio++;
    }
        
    return fila->item[fila->inicio];
}//end removerFila()


//---------------------------------------------
t_fila* getFila(int tamanho){
    
    t_fila* fila = (t_fila*) malloc(sizeof(t_fila));
    fila->item   = (int *) malloc(tamanho*sizeof(int));

    fila->tamanho = tamanho;
    fila->inicio  = 0;
    fila->fim     = 0;

    return fila;
}//end getFila()


//---------------------------------------------
void liberaFila(t_fila* fila){

    free(fila->item);
    free(fila);

}//end liberaFila()


//---------------------------------------------
void imprimirFila(t_fila* fila){
    int i;

    if(filaVazia(fila)){
        printf("Fila Vazia!\n");
        return;
    }

    printf("++++++++++++++++++++++++++\n");
    for(i = 0; i <= fila->tamanho-1; i++){
        printf("%d", fila->item[i]);

        if(i < fila->tamanho-1)
            printf(" -> ");
    }

    printf("\n");

    printf("Inicio - pos: %d valor:%d \n", fila->inicio, fila->item[fila->inicio] );
    printf("Fim    - pos: %d valor:%d \n", fila->fim,    fila->item[fila->fim] );
    
}
