#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int num;
  struct no* prox;

}No;

typedef struct head{
  struct no* fim;
  struct no* ini;

}Header;

No *insere_ordenado(int n, No *p, Header *h);
void imprime(No* l);

int main(){

  int N, i = 6;
  No *l;
  Header *h;
  l = NULL;

  while(i>0){
    scanf("%d",&N);
    l = insere_ordenado(N,l,h);
    i--;
  }

  imprime(l);

  return 0;
}

No *insere_ordenado(int n, No *p, Header *h){

  No *aux1, *aux2;

  if(p == NULL){
    p = (No *) malloc(sizeof(No));
    p->num = n;
    p->prox = NULL;
    h->ini = p;
    h->fim = p;
  }
  else if(n > h->ini->num){
    p = (No *) malloc(sizeof(No));
    p->num = n;
    p->prox = h->ini;
    h->ini = p;
  }
  else if(n < h->ini->num){

    aux1 = h->ini;

    while(aux1 != NULL && aux1->num > n){
      aux2 = aux1;
      aux1 = aux1->prox;
    }

    if(aux1 == NULL){
        p = (No *) malloc(sizeof(No));
        p->num = n;
        p->prox = NULL;
        aux2->prox = p;
        h->fim = p;
    }
    else{
      p = (No *) malloc(sizeof(No));
      p->num = n;
      p->prox = aux1;
      aux2->prox = p;
    }

  }

  return h->ini;

}

void imprime(No* l){

  No *aux;
  aux = l;

  while(aux != NULL){
    printf("%d ",aux->num);
    aux = aux->prox;
  }
  printf("\n");
}
