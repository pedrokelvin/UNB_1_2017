
#include <stdlib.h>
#include <stdio.h>

#define VAZIA -1

typedef struct pilha{
    int topo;
    int *item;
    int tamanho;
} t_pilha;


t_pilha*  getPilha(int tamanho);
void      liberaPilha(t_pilha* pilha);

int       pilhaVazia(t_pilha* pilha);
int       pilhaCheia(t_pilha* pilha);

void      push(t_pilha* pilha, int valor);
int       pop(t_pilha* pilha);

int       topo(t_pilha* pilha);

void      imprimirPilha(t_pilha* pilha);



/*Implementação das Assinaturas de Funções*/
int topo(t_pilha* pilha){

    if(pilhaVazia(pilha)){
        printf("A pilha está vazia!\n");
        liberaPilha(pilha);
        exit(1);
    }

    return pilha->item[pilha->topo];
}

int pop(t_pilha* pilha){
    
    if(pilhaVazia(pilha)){
        printf("Ocorreu um underflow na pilha!\n");
        liberaPilha(pilha);
        exit(1);
    }

    return pilha->item[pilha->topo--];

}//end pop()

void push(t_pilha* pilha, int valor){
    
    if(pilhaCheia(pilha)){
        printf("Ocorreu overflow na pilha!\n");
        liberaPilha(pilha);
        exit(1);
    }

    pilha->item[++pilha->topo] = valor;

}//end push


int pilhaVazia(t_pilha* pilha){
    return ( pilha->topo == VAZIA );
}//end pilhaVazia()


int pilhaCheia(t_pilha* pilha){
    return( pilha->topo == (pilha->tamanho-1));
}//end pilhaCheia()


t_pilha*  getPilha(int tamanho){
    t_pilha* retorno = (t_pilha *) malloc(sizeof(t_pilha));

    retorno->item    = (int *) malloc(tamanho*sizeof(int));
    retorno->tamanho = tamanho;
    retorno->topo    = VAZIA;

    return retorno;
}//end getPilha



void liberaPilha(t_pilha* pilha){
    free(pilha->item);
    free(pilha);
}//end liberaPilha()


int main(){
    t_pilha* pilha = getPilha(10);
    char c, expressao[100];
    int valida     = 1;
    int i          = 0;
    

    printf("Digite a expressao: \n");
    scanf("%[^\n]", expressao);


    while( expressao[i] != '\0' && valida ){

        if( expressao[i] == '(' || 
            expressao[i] == '[' || 
            expressao[i] == '{' ) {
            
            push(pilha, (int) expressao[i]);
        }

        if( expressao[i] == ')' || 
            expressao[i] == ']' || 
            expressao[i] == '}' ) {
            
            if(pilhaVazia(pilha)){
                valida = 0;
                break;
            }else{
                c = (char) pop(pilha);

                switch(expressao[i]){
                    case ')':
                        if(c != '(')
                            valida = 0;
                        break;
                    case ']':
                        if(c != '[')
                            valida = 0;
                        break;
                    case '}':
                        if(c != '{')
                            valida = 0;
                        break;
                }//end switch
                

            }//end if pilhaVazia
            
        }//end if expressao

        i++;

    }//end while

    if( !pilhaVazia(pilha) )
        valida = 0;

    printf("\nA expressao ");

    if(!valida){
        printf(" NAO ");
    }

    printf(" válida!\n");




    liberaPilha(pilha);
    return 0;
}























