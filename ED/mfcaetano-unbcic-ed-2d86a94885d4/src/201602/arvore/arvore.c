#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

#include "fila.h"


//-------------------------------------------
t_no* remove_no(t_no* raiz, int numero){
    t_no* ptr_no, *ptr_return, *ptr_pai, *ptr_fusao;    

    if(raiz == NULL)
        return NULL;

    ptr_no  = busca(raiz, numero);

    if(ptr_no == NULL)
        return NULL;

    ptr_pai = busca_pai(raiz, ptr_no->dado);

    //não tem filhos
    if(ptr_no->esq == NULL && ptr_no->dir == NULL ){
        ptr_return = NULL;    
    }
    
    //tem somente um filho
    if((ptr_no->esq != NULL && ptr_no->dir == NULL ) || 
       (ptr_no->esq == NULL && ptr_no->dir != NULL )){

        if(ptr_no->esq != NULL){
            ptr_return = ptr_no->esq;
        }else{
            ptr_return = ptr_no->dir;
        }

    }

    //tem dois filhos
    if(ptr_no->esq != NULL && ptr_no->dir != NULL ){
        ptr_return     = ptr_no->esq;
        ptr_fusao      = busca_folha_dir(ptr_no->esq);
        ptr_fusao->dir = ptr_no->dir;
    }


    if(ptr_pai != NULL){
        if(ptr_pai->esq != NULL && ptr_pai->esq->dado == ptr_no->dado){
            ptr_pai->esq = ptr_return;
        }else if(ptr_pai->dir != NULL && ptr_pai->dir->dado == ptr_no->dado){
            ptr_pai->dir = ptr_return;
        }

        ptr_return = raiz;
    }

    free(ptr_no);
    return ptr_return;

}//end remove_no()


//---------------------------------------------------
int conta_folhas(t_no* raiz){

    if(raiz == NULL)
        return 0;

    if( raiz->esq == NULL && raiz->dir == NULL )
        return 1;

    return conta_folhas(raiz->esq) + conta_folhas(raiz->dir);

}//end conta_folhas()


//---------------------------------------------------
int altura(t_no* raiz){

    if(raiz == NULL)
        return 0;

    int alt_e = altura(raiz->esq);
    int alt_d = altura(raiz->dir);

    if(alt_e < alt_d)
        return alt_d + 1;
    else
        return alt_e + 1;

}//end altura 












//---------------------------------------------------
t_no* busca_folha_dir(t_no* raiz){

    if( raiz != NULL && raiz->dir == NULL )
        return raiz;

    return busca_folha_dir(raiz->dir);
}


//-------------------------------------------
t_no* busca(t_no* raiz, int dado){
    
    if(raiz == NULL)
        return NULL;

    if(raiz->dado > dado)
        return busca(raiz->esq, dado);

    if(raiz->dado < dado)
        return busca(raiz->dir, dado);

    return raiz;

}//end busca()


//-------------------------------------------
void percurso_largura(t_no* raiz){

    t_fila* fila = getFila(10);
    t_no* no     = NULL; 

    if(raiz == NULL)
        return;

    inserirFila(fila, raiz);

    while(!filaVazia(fila)){

        no = removerFila(fila);

        printf("[%d]\n", no->dado);

        if(no->esq != NULL){
            inserirFila(fila, no->esq);
        }

        if(no->dir != NULL){
            inserirFila(fila, no->dir);
        }
    }

}//end percurso_largura















//-------------------------------------------
void pos_ordem(t_no* raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d\n", raiz->dado);
    }

}//end pos_ordem


//-------------------------------------------
void em_ordem(t_no* raiz){

    if(raiz != NULL){
        em_ordem(raiz->esq);
        printf("%d\n", raiz->dado);
        em_ordem(raiz->dir);
    }

}//end em_ordem()


//-------------------------------------------
void pre_ordem(t_no* raiz){

    if(raiz != NULL){
        printf("%d\n", raiz->dado);

        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
    

}//end em_ordem()



//-------------------------------------------
t_no* criaNo(int dado){
    t_no* ptr = (t_no *) malloc(sizeof(t_no));

    ptr->dado = dado;
    ptr->esq  = NULL;
    ptr->dir  = NULL;

    return ptr;
}//end criaNo()


//-------------------------------------------
t_no* busca_pai(t_no* raiz, int dado){

    if( raiz == NULL || raiz->dado == dado )
        return NULL;

    if(raiz->dado > dado){

        if(raiz->esq != NULL && raiz->esq->dado == dado)
            return raiz;

        return busca_pai(raiz->esq, dado);

    }else if(raiz->dado < dado){

        if(raiz->dir != NULL && raiz->dir->dado == dado)
            return raiz;

        return busca_pai(raiz->dir, dado);
    }

}//end busca_pai()


//-------------------------------------------
t_no* inserir(t_no* raiz, int dado){

    if(raiz == NULL){
        return criaNo(dado);
    }else{
        if( raiz->dado > dado ){
            raiz->esq = inserir(raiz->esq, dado);
        }else if(raiz->dado < dado){
            raiz->dir = inserir(raiz->dir, dado);
        }
    } 

    return raiz;
}//end inserir()










