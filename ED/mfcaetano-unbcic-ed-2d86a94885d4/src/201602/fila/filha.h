
#ifndef __FILA_H__
#define __FILA_H__

#define VAZIA -1

typedef struct fila {
    int *item;
    int tamanho;
    int inicio, fim;
} t_fila;


t_fila* getFila(int tamanho);
void    liberaFila(t_fila* fila);

void    inserirFila(t_fila* fila, int valor);
int     removerFila(t_fila* fila);

int     filaVazia(t_fila* fila);
//int     filaCheia(t_fila* fila);

void    imprimirFila(t_fila* fila);




#endif
