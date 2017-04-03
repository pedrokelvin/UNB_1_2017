#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct nodo{
  float coeficiente;
  int expoente;
  struct nodo *proximo;
}p_nodo;

typedef struct polinomio{
  p_nodo *primeiro;
}l_polinomio;

p_nodo *getNodo();
l_polinomio *getPolinomio();
void inserir_nodo(l_polinomio *pol, float coef,int expo);
void imprime_polinomio(l_polinomio *pol, char n);
float calcula_polinomio(l_polinomio *pol, float x);

int main(){

  int expo, i;
  char p;
  l_polinomio* polinomio = getPolinomio();
  float s, coef;

  inserir_nodo(polinomio, 10, 2);
  inserir_nodo(polinomio,  6, 1);
  inserir_nodo(polinomio, -1, 0);
  inserir_nodo(polinomio, -2, 2);

  /* -----Nesta parte o usuário escolhe quantos termos terão o polinômio----

  scanf("%d", &i);
  while(i){
    scanf("%f %d",&coef,&expo);
    inserir_nodo(polinomio,coef,expo);
    i--;

  }*/

  imprime_polinomio(polinomio,'p');
  s = calcula_polinomio(polinomio, 4);
  printf("%.2f\n",s);

  return 0;
}

p_nodo *getNodo(){

  p_nodo *p;
  p = NULL;

  return p;
}

l_polinomio* getPolinomio(){

  l_polinomio *head;
  head = (l_polinomio *) malloc(sizeof(l_polinomio));
  head->primeiro = NULL;

  return head;
}

void inserir_nodo(l_polinomio *pol, float coef,int expo){

  p_nodo *p, *aux1, *aux2;

  if(pol->primeiro == NULL){
      p = (p_nodo *) malloc(sizeof(p_nodo));
      p->coeficiente = coef;
      p->expoente = expo;
      p->proximo = NULL;
      pol->primeiro = p;
  }

  else if(expo <= pol->primeiro->expoente){

    if(expo < pol->primeiro->expoente){
        p = (p_nodo *) malloc(sizeof(p_nodo));
        p->expoente = expo;
        p->coeficiente = coef;
        p->proximo = pol->primeiro;
        pol->primeiro = p;
    }
    else if(expo == pol->primeiro->expoente){
      pol->primeiro->coeficiente = pol->primeiro->coeficiente + coef;
    }
  }
  else if(expo > pol->primeiro->expoente){
    aux1 = pol->primeiro;

    while(aux1 != NULL && aux1->expoente < expo){
      aux2 = aux1;
      aux1 = aux1->proximo;
    }

    if(aux1 != NULL && aux1->expoente == expo){
      aux1->coeficiente = aux1->coeficiente + coef;
    }
    else{
      p = (p_nodo *) malloc(sizeof(p_nodo));
      p->coeficiente = coef;
      p->expoente = expo;
      aux2->proximo = p;
      p->proximo = aux1;
    }
  }

}

void imprime_polinomio(l_polinomio *pol, char n){

  p_nodo *aux;
  aux = pol->primeiro;

  printf("%c (X) = ",n);

  while(aux != NULL){

      if(aux->expoente == 0){
        printf("%.2f",aux->coeficiente);

      }else if(aux == pol->primeiro){
        if(aux->coeficiente > 0)
          printf(" +%.2f*X^%d",aux->coeficiente,aux->expoente);
        else
          printf(" %.2f*X^%d",aux->coeficiente,aux->expoente);
      }
      else{
        if(aux->coeficiente > 0)
          printf(" +%.2f*X^%d",aux->coeficiente,aux->expoente);
        else
          printf(" %.2f*X^%d",aux->coeficiente,aux->expoente);
      }

      aux = aux->proximo;
  }

  printf("\n");

}

float calcula_polinomio(l_polinomio *pol, float x){

  float soma = 0.00;
  p_nodo *aux;
  aux = pol->primeiro;

  while(aux != NULL){
    soma += aux->coeficiente*pow(x,aux->expoente);
    aux = aux->proximo;
  }

  return soma;

}
