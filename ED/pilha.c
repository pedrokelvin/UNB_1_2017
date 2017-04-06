

/* IMPLEMENTAÇÃO DE PILHA COM AS ASSINATURAS DO PROFESSOR*/

#include <stdio.h>
#include <stdlib.h>

#define VAZIA -1

typedef struct pilha{
  int topo, tamanho;
  int *item;

}t_pilha;

t_pilha*  getPilha(int tamanho);
void      liberaPilha(t_pilha* pilha);
int       pilhaVazia(t_pilha* pilha);
int       pilhaCheia(t_pilha* pilha);
void      push(t_pilha* pilha, int valor);
int       pop(t_pilha* pilha);
int       topo(t_pilha* pilha);
void      imprimirPilha(t_pilha* pilha);


int main(){

  t_pilha * pilha = getPilha(10);
  char c, expressao[100];
  int valida = 1;
  int i = 0;

  printf("Digite a expressao: ");
  scanf("%s",expressao);

  while(expressao[i] != '\0' && valida){

    if(expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{'){
      push(pilha,(int) expressao[i]);
    }
    else if(expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}'){

      if(pilhaVazia(pilha))
        valida = 0;
      else{
        c = (char) pop(pilha);

        switch(expressao[i]){
            case ')':
              if(c != '(')
                valida = 0;
            break;

            case '}':
              if(c != '{')
                valida = 0;
            break;

            case ']':
              if(c != '[')
                valida = 0;
            break;
        }//end switch

      }//end else

    }//end else if (expressao)

    i++;
  }//end while

  printf("A pilha ");

  if(valida)
    printf("eh valida.\n");
  else
    printf("nao eh valida\n");

  return 0;
}

t_pilha* getPilha(int tamanho){
  t_pilha * retorno = (t_pilha *) malloc(sizeof(t_pilha));

  retorno->item = (int *) malloc(tamanho*sizeof(int));
  retorno->tamanho = tamanho;
  retorno->topo = VAZIA;

  return retorno;
}

void liberaPilha(t_pilha* pilha){
  free(pilha->item);
  free(pilha);
}

int pilhaVazia(t_pilha* pilha){
  return (pilha->topo == VAZIA);
}

int pilhaCheia(t_pilha* pilha){
  return (pilha->topo == (pilha->tamanho - 1));
}

void push(t_pilha* pilha, int valor){

  if(pilhaCheia(pilha)){
    printf("Ocorreu um overflow na pilha\n");
    liberaPilha(pilha);
    exit(1);
  }

  pilha->item[++pilha->topo] = valor;
}

int pop(t_pilha* pilha){
  if(pilhaVazia(pilha)){
    printf("Ocorreu um underflow\n");
    liberaPilha(pilha);
    exit(1);
  }

  return (pilha->item[pilha->topo--]);
}

int topo(t_pilha* pilha){
  if(pilhaVazia(pilha)){
    printf("A pilha esta vazia\n");
    liberaPilha(pilha);
    exit(1);
  }

  return (pilha->item[pilha->topo]);
}

void imprimirPilha(t_pilha* pilha){
  int aux;
  aux = pilha->topo;

  if(pilhaVazia(pilha)){
    printf("A pilha esta vazia\n");
    liberaPilha(pilha);
    exit(1);
  }
  while(aux--){
    printf("%c\n",pilha->item[aux]);
  }
}
