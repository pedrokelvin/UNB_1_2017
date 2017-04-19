#include<stdio.h>
#include<stdlib.h>

typedef struct pilha{
  char *caracter;
  int topo;
}p_nodo;

p_nodo *getNodo(p_nodo *pilha);
int desempilha(char c, p_nodo *pilha);
p_nodo *empilha(char c, p_nodo *pilha);
int pilhaVazia(p_nodo *pilha);
void liberaPilha(p_nodo *pilha);
void validacao(char *expre);
void imprimePosfixa(char *expre);


int main(){

  char *expre;
  expre = (char *) malloc(sizeof(char)*100);
  scanf("%s",expre);
  getchar();

  validacao(expre);
  imprimePosfixa(expre);

  return 0;
}

//Inicializa uma pilha
p_nodo *getNodo(p_nodo *pilha){
  pilha = (p_nodo *) malloc(sizeof(p_nodo));
  pilha->caracter = (char *) malloc(sizeof(char)*100);
  pilha->topo = 0;

  return pilha;
} //end getNodo

p_nodo *empilha(char c, p_nodo *pilha){

    pilha->caracter[pilha->topo++] = c;

    return pilha;
}//end empilha

int pilhaVazia(p_nodo *pilha){
  if(pilha->topo)
    return 0;
  return 1;

}//end pilhaVazia

int desempilha(char c, p_nodo *pilha){

  char aux = pilha->caracter[pilha->topo - 1];

  if(pilha->topo == 0)
    return 0;

  switch(aux){

      case '{':
        if(c == '}'){
          --pilha->topo;
          return 1;
        }

      break;

      case '(':
        if(c == ')'){
          --pilha->topo;
          return 1;
        }
      break;

      case '[':
        if(c == ']'){
          --pilha->topo;
          return 1;
        }
      break;

  }

  return 0;
}//end desempilha

void liberaPilha(p_nodo *pilha){
  free(pilha->caracter);
  free(pilha);
}

//Avalia a expressão quanto a disposição dos parênteses
void validacao(char *expre){

  int i = 0;
  int verif = 1;
  p_nodo *pilha = getNodo(pilha);

  while(expre[i] != '\0' && verif){

    if(expre[i] == '(' || expre[i] == '{' || expre[i] == '[')
      pilha = empilha(expre[i], pilha);
    else if(expre[i] == '}' || expre[i] == ')' || expre[i] == ']')
      verif = desempilha(expre[i], pilha);

    if(expre[++i] == '\0' && verif)
      verif = pilhaVazia(pilha);

  }

  if(verif == 1)
    printf("Valida\n");
  else if(verif == 0)
    printf("Invalida\n");

  liberaPilha(pilha);

}

//Imprime a expressão na forma posfixa
void imprimePosfixa(char *expre){

  p_nodo *pilha = getNodo(pilha);
  int i = 0;

  while(expre[i] != '\0'){

    if(expre[i] == '(')
      pilha = empilha(expre[i],pilha);

    else if(expre[i] != ')'){

      if(expre[i] == '/'){

        if(pilhaVazia(pilha))
          pilha = empilha(expre[i],pilha);

        else if(pilha->caracter[pilha->topo - 1] != '*' && pilha->caracter[pilha->topo - 1] != '/')
          pilha = empilha(expre[i], pilha);

        else{
            printf("%c",pilha->caracter[pilha->topo-1]);
            pilha->topo--;
            pilha = empilha(expre[i], pilha);
          }
        } //end '/'

        else if(expre[i] == '*'){

          if(pilhaVazia(pilha))
            pilha = empilha(expre[i],pilha);

          else if(pilha->caracter[pilha->topo - 1] != '*' && pilha->caracter[pilha->topo - 1] != '/'){
            pilha = empilha(expre[i], pilha);

          }
          else{
            printf("%c",pilha->caracter[pilha->topo-1]);
            pilha->topo--;
            pilha = empilha(expre[i], pilha);
          }
        } //end '*'

        else if(expre[i] == '+'){

          if(pilhaVazia(pilha) || pilha->caracter[pilha->topo-1] == '('){
            pilha = empilha(expre[i], pilha);
          }

          else{
            printf("%c",pilha->caracter[pilha->topo-1]);
            pilha->topo--;
            pilha = empilha(expre[i], pilha);
          }

        } //end '+'

        else if(expre[i] == '-'){
          if(pilhaVazia(pilha) || pilha->caracter[pilha->topo-1] == '('){
                pilha = empilha(expre[i], pilha);
            }

          else{
            printf("%c",pilha->caracter[pilha->topo-1]);
            pilha->topo--;
            pilha = empilha(expre[i], pilha);
          }
        } //end '-'

        else
          printf("%c",expre[i]);

      }

      i++;

      if(expre[i] == '\0' || expre[i] == ')'){

        while(pilha->topo > 0 && pilha->caracter[pilha->topo - 1] != '(' ){
          printf("%c",pilha->caracter[--pilha->topo]);
        }

        if(pilha->caracter[pilha->topo - 1] == '(')
          --pilha->topo;
      }

  }

  printf("\n");
}
