
typedef struct pilha{
  double *caracter;
  int topo;
}p_nodo;

p_nodo *getNodo(p_nodo *pilha);
p_nodo *desempilha(p_nodo *pilha);
p_nodo *empilha(double c, p_nodo *pilha);
int pilhaVazia(p_nodo *pilha);
void liberaPilha(p_nodo *pilha);
int validacao(char *expre);
void imprimePosfixa(char *expre);
void calculadora();
void imprime_pilha(int i, p_nodo *pilha);
double conv(char *a);
void calcula_posfixa(char *a);
