#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>


//---------------------------------------------
int topo(t_pilha* pilha){

    if(pilhaVazia(pilha)){
        printf("Ocorreu underflow na pilha!\n");
        liberaPilha(pilha);
        exit(1);
    }

    return pilha->item[pilha->topo];
}//end 


//---------------------------------------------
void imprimirPilha(t_pilha* pilha){
    int i;

    if(pilhaVazia(pilha)){
        printf("Pilha Vazia!\n");
        return;
    }

    printf("++++++++++++++++++++++++++\n");
    for(i = pilha->topo; i > VAZIA; i--)
        printf("%d\n", pilha->item[i]);
    
}


//---------------------------------------------
void push( t_pilha* pilha, int valor){

    if( pilhaCheia(pilha) ){
        printf("Ocorreu overflow na pilha!\n");
        liberaPilha(pilha);
        exit(1);
    }  

    pilha->item[++pilha->topo] = valor;

}//end push()

//---------------------------------------------
int  pop(t_pilha* pilha){
    
    if(pilhaVazia(pilha)){
        printf("Ocorreu underflow na pilha!\n");
        liberaPilha(pilha);
        exit(1);
    }

    return pilha->item[pilha->topo--];
}//end pop()



//---------------------------------------------
int pilhaVazia(t_pilha* pilha){
    return ( pilha->topo == VAZIA );
}//end pilhaVazia()

//---------------------------------------------
int pilhaCheia(t_pilha* pilha){
    return ( pilha->topo == pilha->tamanho );
}//end pilhaCheia()


//---------------------------------------------
t_pilha* getPilha(int tamanho){
    t_pilha* retorno = (t_pilha *) malloc(sizeof(t_pilha));
    retorno->item    = (int *) malloc(tamanho*sizeof(int));
    retorno->tamanho = tamanho;
    retorno->topo    = VAZIA;
    return retorno;
}//end getPilha();


//---------------------------------------------
void liberaPilha(t_pilha* pilha){
    free(pilha->item);
    free(pilha);

}//end liberaPilha()
