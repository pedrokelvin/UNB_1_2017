

#ifndef FILA_H_

#define FILA_H_

 typedef struct elemento {
    int dado;
    struct elemento* proximo;
} t_elemento;

typedef struct fila{
    t_elemento* primeiro;
    t_elemento* ultimo;
} t_fila;


void insereNaFila(int valor, t_fila* fila);

int  RemoveDaFila(t_fila * fila);

void imprime_fila( t_fila* fila);
void apaga_fila(t_fila* fila);

t_fila* aloca_fila();


#endif
