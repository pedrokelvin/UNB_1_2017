#include "arvore.h"
#include "fila.h"
#include <stdio.h>

int main(){
    t_no* raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 17);
    raiz = inserir(raiz, 72);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 54);
    raiz = inserir(raiz, 76);
    raiz = inserir(raiz, 9);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 19);
    raiz = inserir(raiz, 67);

    printf("Pre-ordem:\n");
    pre_ordem(raiz);

    printf("Pós-ordem:\n");
    pos_ordem(raiz);

    percurso_largura(raiz);


/*    int valor = 50;

    if(raiz = remove_no(raiz, valor))
        printf("Número %d removido com sucesso! \n", valor);
    else
        printf("Não foi possível encontrar número %d na árvore! \n", valor);

    printf("Pre-ordem:\n");
    pre_ordem(raiz);


    printf("Em-ordem:\n");
    em_ordem(raiz);

    printf("Pós-ordem:\n");
    pos_ordem(raiz);

    percurso_largura(raiz);

    printf("A arvore possui %d folhas \n", conta_folhas(raiz));

    printf("Esta arvore em altura: %d \n", altura(raiz));

    int valor = 68;

    t_no* no = busca(raiz, valor);

    if(no == NULL){
        printf("Número não encontrado!\n");
    }else{
        printf("Valor: %d foi encontrado!\n", no->dado);
    }

    valor = 19;
    no = busca_pai(raiz, valor);

    if(no == NULL){
        printf("Número %d é orfão!\n", valor);
    }else{
        printf("Pai de %d é %d!\n", valor, no->dado);
    }

    valor = 50;

    if(remove_no(raiz, valor))
        printf("Número %d removido com sucesso! \n", valor);
    else
        printf("Não foi possível encontrar número %d na árvore! \n", valor);
*/

}






