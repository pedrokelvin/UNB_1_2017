#include <stdlib.h>
#include <stdio.h>

typedef struct fila{
    int *item;
    int tamanho;
    int inicio, fim;
} t_fila;


//Assinaturas de Funções
t_fila* getFila(int tamanho);
void    liberaFila(t_fila* fila);
void    inserir(t_fila* fila, int valor);
int     remover(t_fila* fila);


//Implementações
t_fila* getFila(int tamanho){
    t_fila* fila  = (t_fila *) malloc(sizeof(t_fila));
    fila->item    = (int *) malloc(tamanho*sizeof(int));

    fila->tamanho = tamanho;
    fila->inicio  = 0;
    fila->fim     = fila->inicio;

    return fila;
}//end getFila


void liberaFila(t_fila* fila){
    free(fila->item);
    free(fila);
}//end liberaFila()


void inserir(t_fila* fila, int valor){  
    if( fila->fim == fila->tamanho-1 )
        fila->fim = 0;
    else
        fila->fim++;

    if(fila->fim == fila->inicio){
        printf("Ocorreu um overflow de fila \n");
        exit(1);
    }

    fila->item[fila->fim] = valor;
}//end inserir

int remover(t_fila* fila){

    if(fila->inicio == fila->fim){
        printf("Underflow na fila! \n");
        exit(1);
    }
    
    if(fila->inicio == fila->tamanho-1)
        fila->inicio = 0;
    else
        fila->inicio++;

    return fila->item[fila->inicio];
}//end remover










int  main(){
    t_fila* fila = getFila(10);

    for(int i = 0; i < 9; i++)
        inserir(fila, i);

    for(int i = 0; i < 9; i++)
        printf("%d \n", remover(fila));    

    liberaFila(fila);
}









