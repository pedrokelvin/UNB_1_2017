/**
* @file declaracoes.h
* @author Pedro Kelvin
* @date 1 Maio 2017
* @brief Arquivo para a execução do programa de conversão de uma expressão da
* forma infixa para a forma pós-fixa. Bem como a reprensentação de uma calculadora
* através do uso de pilha.
* Trabalho proposta para a disciplina de Estrutura de Dados - Unb
*/

typedef struct pilha{
  double *caracter;
  int topo;
}p_nodo;

/**
* @brief Função que inicializa uma estrutura do tipo p_nodo.
* @return Retorna também uma estrutura do tipo pilha para a chamada inicial.
*/
p_nodo *getNodo(p_nodo *pilha);

/**
* @brief Função que tem por objetivo retirar um elemento na pilha, sempre o do topo.
* @param pilha Recebe sempre a pilha em questão que deve ser alterada.
* @return Retorna a mesma pilha já atualizada sem o elemento (caso não esteja vazia)
*/
p_nodo *desempilha(p_nodo *pilha);

/**
* @brief Função que empilha um elemento na pilha
* @param c É um recebidp um número do tipo double ou um caracter para ser empilhado
* @param pilha O segundo parâmetro é a pilha em que deve ser realizada a operação
* @return Retorna a pilha modificada
*/
p_nodo *empilha(double c, p_nodo *pilha);

/**
* @brief Realiza a liberação da memória de uma estrura do tipo pilha
* @param Recebe a própria pilha onde deve ser realizada a modificação
*/
void liberaPilha(p_nodo *pilha);

/**
* @brief Essa função realiza a conversão da forma infixa para a pós-fixa,
* caso seja uma expressão válida.
* @param expre O parâmetro recebido é a string inserida pelo usuário.
*/
void imprimePosfixa(char *expre);

/**
* @brief Essa função realiza o calculo de operandor em uma pilha, de acordo
* como é feito em uma notação pós-fixa(os dois operandos logo atrás do operador são manipulados).
*/
void calculadora();

/**
* @brief Função utilizada dentro da função calculadora(), onde é atualizada sempre após uma
* operação o estado atual da pilha.
* @param i É o iterador recebido que está em constante mudança devido à quantidade de
* valores que estão sendo colocados ou retirados da pilha
*/
void imprime_pilha(int i, p_nodo *pilha);

/**
* @brief Função que avalia a expressão já na forma pós-fixa e executa os comandos para
* a resolução desta expressão
* @param a Essa é a string recebida pela função, que é varrida do início ao fim para
* a entrega do valor final.
*/
void calcula_posfixa(char *a);

/**
* @brief Verifica se a pilha está vazia ou não
* @return Retorna o valor 1 caso estejá realmente vazia (topo da pilha igual a zero).
* E retorna 0 quando ela tem elementos (topo > 0).
*/
int pilhaVazia(p_nodo *pilha);

/**
* @brief Função avalia se a expressão recebida na forma infixa está inserida de
* forma correta (disposição dos parenteses corretos).
* @param expre É a string na forma infixa avaliada.
* @return Retorna 1 caso seja válida a expressão, e 0 caso não seja válida.
*/
int validacao(char *expre);

/**
* @brief Essa função faz a conversão de uma string para um número do tipo double.
* A função "atoi" que já implementada em C na biblioteca "string.h" converte uma string
* para um inteiro. Mas no programa em questão houve a necessidade de se converter
* essa string para um tipo double.
* @param a String que contem o valor a ser transformado. Ex: a[4] = {1,3,.,4}. Esse
* seria o número 13.4 caso estivesse representado em uma string de caracteres.
* @return Retorna o número modificado para a sua chamada original.
*/
double conv(char *a);
