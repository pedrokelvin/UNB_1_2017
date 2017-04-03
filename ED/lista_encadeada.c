#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista* prox;

}Lista;

typedef struct head{
  int indice;
  struct lista *ini;
  struct lista *fim;

}Header;

Lista *inserir_lista(int n, Lista *p, Header *h);
void imprimir(Header *h);

int main(){

  int i = 5, N;
  Lista *l;
  Header *h;
  l = NULL;

  while(i>0){
      scanf("%d",&N);
      l = inserir_lista(N,l,h);
      i--;
  }

  imprimir(h);

  return 0;
}


Lista *inserir_lista(int n, Lista *p, Header *h){

  Lista *aux;

  if(p == NULL){
    p = (Lista *) malloc(sizeof(Lista));
    p->num = n;
    p->prox = NULL;
    h->ini = p;
    h->fim = p;
  }

  else{
    aux = (Lista *) malloc(sizeof(Lista));
    aux->num = n;
    aux->prox = NULL;
    h->fim->prox = aux;
    h->fim = aux;
  }

  return h->ini;

}

void imprimir(Header *h){

  Lista *aux;
  aux = h->ini;

  while(aux != NULL){
    printf("%d ",aux->num);
    aux = aux->prox;
  }

}
