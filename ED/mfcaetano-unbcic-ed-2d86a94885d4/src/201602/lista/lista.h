

#ifndef LISTA_H_

#define LISTA_H_

 typedef struct elemento {
    int dado;
    struct elemento* proximo;
} t_elemento;

typedef struct lista{
    t_elemento* primeiro;
    t_elemento* ultimo;
} t_lista;


void insereInicio(int valor, t_lista* lista);
void insereFinal(int valor, t_lista * lista);

int  removeInicio(t_lista * lista);
int  removeFinal(t_lista * lista);

int  estaVazia(t_lista * lista);

void inserir(int pos, int valor, t_lista * lista);
int  remover(int pos, t_lista * lista);

void imprime_lista( t_lista* lista);
void apaga_lista(t_lista* lista);

t_lista* aloca_lista();












#endif
