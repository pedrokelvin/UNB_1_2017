#include <stdio.h>
#include "pilha.h"

int main(){
    int i      = 0;
    int valida = 1;
    char c, expressao[100];
    t_pilha* pilha = getPilha(10);
    
    printf("Digite a expressão: \n");
    scanf("%[^\n]", expressao);

    while( (expressao[i] != '\0') && (valida != 0) ){
        printf("simbolo: %c valor: %d\n", expressao[i], (int) expressao[i]);

        if( (expressao[i] == '(') || (expressao[i] == '[') || (expressao[i] == '{') ) 
            push(pilha, (int) expressao[i]);       

        if( (expressao[i] == ')') || (expressao[i] == ']') || (expressao[i] == '}') ){
            if( pilhaVazia(pilha) )
                valida = 0;
            else{
                c = (char) pop(pilha);

                switch(expressao[i]){
                    case ')':
                        if( c != '(' )
                            valida = 0;
                        break;
                    case ']':
                        if( c != '[' )
                            valida = 0;
                        break;
                    case '}':
                        if( c != '{' )
                            valida = 0;
                        break;
                }
                
            }
        }

        i++;

    }//end while

    if( !pilhaVazia(pilha) )
        valida = 0;

    printf("\n A expressao: ");

    if(!valida)
        printf(" NAO ");

    printf(" eh valida \n");   

    liberaPilha(pilha);
}
