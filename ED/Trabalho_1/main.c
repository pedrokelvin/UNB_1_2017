#include<stdio.h>
#include<stdlib.h>

typedef struct pilha{
  char *caracter;
  int indice;
}p_nodo;

p_nodo *getNodo();
int desempilha(char c, p_nodo *pilha);
p_nodo *empilha(char c, p_nodo *pilha);
int pilhaVazia(p_nodo *pilha);

int main(){

  char expre[100];
  int i = 0;
  int verif = 1;
  p_nodo *pilha = (p_nodo *) malloc(sizeof(p_nodo));
  pilha = getNodo();

  scanf("%s",expre);

  while(expre[i] != '\0' && verif){

    if(expre[i] == '(' || expre[i] == '{' || expre[i] == '[')
      pilha = empilha(expre[i], pilha);
    else if(expre[i] == '}' || expre[i] == ')' || expre[i] == ']')
      verif = desempilha(expre[i], pilha);

    printf("%d\n",verif);

    if(expre[++i] == '\0' && verif)
      verif = pilhaVazia(pilha);

    printf("%d\n",verif);

  }

  if(verif == 1)
    printf("Valida\n");
  else if(verif == 0)
    printf("Invalida\n");


  return 0;
}

p_nodo *getNodo(){
  p_nodo *pilha = (p_nodo *) malloc(sizeof(p_nodo));
  pilha->caracter = (char *) malloc(sizeof(char)*100);
  pilha->indice = 0;

  return pilha;
}//end getNodo

p_nodo *empilha(char c, p_nodo *pilha){

    pilha->caracter[pilha->indice++] = c;

    return pilha;
}//end empilha

int pilhaVazia(p_nodo *pilha){
  if(pilha->indice)
    return 0;
  return 1;

}//end pilhaVazia

int desempilha(char c, p_nodo *pilha){

  char aux = pilha->caracter[pilha->indice - 1];

  if(pilha->indice == 0)
    return 0;

  switch(aux){

      case '{':
        if(c == '}'){
          --pilha->indice;
          return 1;
        }

      break;

      case '(':
        if(c == ')'){
          --pilha->indice;
          return 1;
        }
      break;

      case '[':
        if(c == ']'){
          --pilha->indice;
          return 1;
        }
      break;

  }

  return 0;
}
