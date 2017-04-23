#include<stdio.h>
#include<stdlib.h>

typedef struct pilha{
  int *caracter;
  int topo;
}p_nodo;

p_nodo *getNodo(p_nodo *pilha);
int desempilha(int c, p_nodo *pilha);
p_nodo *empilha(int c, p_nodo *pilha);
int pilhaVazia(p_nodo *pilha);
void liberaPilha(p_nodo *pilha);
int validacao(char *expre);
void imprimePosfixa(char *expre);
void calcula();
void imprime_pilha(int i, p_nodo *pilha);

int main(){

  int valida,op;
  char *expre;
  expre = (char *) malloc(sizeof(char)*100);

  while(scanf("%d",&op) != EOF){

    switch(op){

      case 1:
        printf("Modo expressao\n");
        getchar();
        scanf("%[^'\n']",expre);
        valida = validacao(expre);
        if(valida)
          imprimePosfixa(expre);
      break;

      case 2:
        calcula();
      break;
    }
  }

  return 0;
}

//Inicializa uma pilha
p_nodo *getNodo(p_nodo *pilha){
  pilha = (p_nodo *) malloc(sizeof(p_nodo));
  pilha->caracter = (int *) malloc(sizeof(int)*100);
  pilha->topo = 0;

  return pilha;
} //end getNodo

p_nodo *empilha(int c, p_nodo *pilha){

    pilha->caracter[pilha->topo++] = c;

    return pilha;
}//end empilha

int pilhaVazia(p_nodo *pilha){
  if(pilha->topo)
    return 0;
  return 1;

}//end pilhaVazia

int desempilha(int c, p_nodo *pilha){

  char aux = pilha->caracter[pilha->topo - 1];

  if(pilha->topo == 0)
    return 0;

  switch(aux){

      case '{':
        if((char) c == '}'){
          --pilha->topo;
          return 1;
        }

      break;

      case '(':
        if((char) c == ')'){
          --pilha->topo;
          return 1;
        }
      break;

      case '[':
        if((char) c == ']'){
          --pilha->topo;
          return 1;
        }
      break;

  }

  return 0;
} //end desempilha

void liberaPilha(p_nodo *pilha){
  free(pilha->caracter);
  free(pilha);
}

//Avalia a expressão quanto a disposição dos parênteses
int validacao(char *expre){

  int i = 0;
  int verif = 1;
  p_nodo *pilha = getNodo(pilha);

  while(expre[i] != '\0' && verif){

    if(expre[i] == '(' || expre[i] == '{' || expre[i] == '[')
      pilha = empilha((int) expre[i], pilha);
    else if(expre[i] == '}' || expre[i] == ')' || expre[i] == ']')
      verif = desempilha((int) expre[i], pilha);

    if(expre[++i] == '\0' && verif)
      verif = pilhaVazia(pilha);
  }

  if(verif == 1)
    printf("Valida\n");
  else if(verif == 0)
    printf("Invalida\n");

  liberaPilha(pilha);
  return verif;

}

//Imprime a expressão na forma posfixa
void imprimePosfixa(char *expre){

  p_nodo *pilha = getNodo(pilha);
  int i = 0, j = 0;
  char expressao[100];

  while(expre[i] != '\0'){

    if(expre[i] == '(')
      pilha = empilha((int) expre[i],pilha);

    else if(expre[i] != ')'){

      if(expre[i] == '/'){

        if(pilhaVazia(pilha))
          pilha = empilha((int) expre[i],pilha);

        else if(pilha->caracter[pilha->topo - 1] != '*' && pilha->caracter[pilha->topo - 1] != '/')
          pilha = empilha((int) expre[i], pilha);

        else{
            printf("%c",pilha->caracter[pilha->topo-1]);
            expressao[j++] = pilha->caracter[pilha->topo-1];
            pilha->topo--;
            pilha = empilha((int) expre[i], pilha);
          }
        } //end '/'

        else if(expre[i] == '*'){

          if(pilhaVazia(pilha))
            pilha = empilha((int) expre[i],pilha);

          else if(pilha->caracter[pilha->topo - 1] != '*' && pilha->caracter[pilha->topo - 1] != '/'){
            pilha = empilha((int) expre[i], pilha);

          }
          else{
            printf("%c",pilha->caracter[pilha->topo-1]);
            expressao[j++] = pilha->caracter[pilha->topo-1];
            pilha->topo--;
            pilha = empilha((int) expre[i], pilha);
          }
        } //end '*'

        else if(expre[i] == '+'){

          if(pilhaVazia(pilha) || pilha->caracter[pilha->topo-1] == '('){
            pilha = empilha((int) expre[i], pilha);
          }

          else{
            printf("%c",pilha->caracter[pilha->topo-1]);
            expressao[j++] = pilha->caracter[pilha->topo-1];
            pilha->topo--;
            pilha = empilha((int) expre[i], pilha);
          }

        } //end '+'

        else if(expre[i] == '-'){
          if(pilhaVazia(pilha) || pilha->caracter[pilha->topo-1] == '('){
                pilha = empilha((int) expre[i], pilha);
            }

          else{
            printf("%c",pilha->caracter[pilha->topo-1]);
            expressao[j++] = pilha->caracter[pilha->topo-1];
            pilha->topo--;
            pilha = empilha((int) expre[i], pilha);
          }
        } //end '-'

        else{
          printf("%c",expre[i]);
          expressao[j++] = expre[i];
        }
      }

      i++;

      if(expre[i] == '\0' || expre[i] == ')'){

        while(pilha->topo > 0 && pilha->caracter[pilha->topo - 1] != '(' ){
          printf("%c",pilha->caracter[--pilha->topo]);
          expressao[j++] = pilha->caracter[pilha->topo];
        }

        if(pilha->caracter[pilha->topo - 1] == '(')
          --pilha->topo;
      }

  }

  printf("\n");

  liberaPilha(pilha);
}

void imprime_pilha(int i, p_nodo *pilha){

  printf("Modo Calculadora\n");

  while(i){
    printf("%d. %d\n",i,pilha->caracter[pilha->topo - i]);
    i--;
  }

}

void calcula(){
  p_nodo *pilha = getNodo(pilha);
  int i = 0, num;

  printf("Pilha Vazia!\n");

  while(scanf("%d",&num) != EOF){

    if(pilhaVazia(pilha)){

      if(num == '*' || num == '/' || num == '-' || num == '+')
        printf("----------------Numero de operandos insuficiente---------");
      else{
        pilha = empilha(num,pilha);
        printf("Modo calculadora\n");
        printf("%d. %d\n",++i,pilha->caracter[pilha->topo-1]);
      }

    }
    else{

      if(num == '*'){ // MULTIPLICAÇÃO

      }
      else if(num == '+'){ // SOMA

      }
      else if(num == '-'){ // SUBTRAÇÃO

      }
      else if(num == '/'){ //DIVISÃO

      }
      else{
        pilha = empilha(num,pilha);
        imprime_pilha(++i,pilha);
      }
    }

    printf("->");
  } //end while

}
