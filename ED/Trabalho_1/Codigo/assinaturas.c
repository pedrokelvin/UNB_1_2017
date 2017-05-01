/**
* @file assinaturas.c
* @author Pedro Kelvin
* @date 1 Maio 2017
* @brief Arquivo para a execução do programa de conversão de uma expressão da
* forma infixa para a forma pós-fixa. Bem como a reprensentação de uma calculadora
* através do uso de pilha.
* Trabalho proposta para a disciplina de Estrutura de Dados - Unb
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "declaracoes.h"


p_nodo *getNodo(p_nodo *pilha){

  pilha = (p_nodo *) malloc(sizeof(p_nodo));
  pilha->caracter = (double *) malloc(sizeof(double)*100);
  pilha->topo = 0;

  return pilha;
} //end getNodo

p_nodo *empilha(double c, p_nodo *pilha){

    pilha->caracter[pilha->topo++] = c;

    return pilha;
}

int pilhaVazia(p_nodo *pilha){

  if(pilha->topo)
    return 0;
  return 1;

}

p_nodo *desempilha(p_nodo *pilha){

    --pilha->topo;

  return pilha;
}

void liberaPilha(p_nodo *pilha){
  free(pilha->caracter);
  free(pilha);
}

int validacao(char *expre){

  int i = 0;
  int verif = 1;
  p_nodo *pilha = getNodo(pilha);

  while(expre[i] != '\0' && verif){

    if(expre[i] == '(')
      pilha = empilha((double) expre[i], pilha);

    else if(expre[i] == ')')
    {
        if(i > 0 && pilha->caracter[pilha->topo-1] == '(')
            pilha = desempilha(pilha);
        else
            verif = 0;
    }

    if(expre[++i] == '\0' && verif)
      verif = pilhaVazia(pilha);
  }

  if(verif == 1)
    printf("\nValida\n");
  else if(verif == 0)
    printf("\nInvalida\n");

  liberaPilha(pilha);
  return verif;
}


void imprimePosfixa(char *expre){

  p_nodo *pilha = getNodo(pilha);
  int i = 0, j = 0;
  char expressao[100];

  while(expre[i] != '\0'){

    if(expre[i] == '(')
      pilha = empilha((double) expre[i],pilha);

    else if(expre[i] != ')'){

      if(expre[i] == '/'){

        if(pilhaVazia(pilha))
          pilha = empilha((double) expre[i],pilha);

        else if(pilha->caracter[pilha->topo - 1] != '*' && pilha->caracter[pilha->topo - 1] != '/')
          pilha = empilha((double) expre[i], pilha);

        else{
            printf("%c",(int) pilha->caracter[pilha->topo-1]);
            expressao[j++] = pilha->caracter[pilha->topo-1];
            pilha->topo--;
            pilha = empilha((double) expre[i], pilha);
          }
        } //end '/'

        else if(expre[i] == '*'){

          if(pilhaVazia(pilha))
            pilha = empilha((double) expre[i],pilha);

          else if(pilha->caracter[pilha->topo - 1] != '*' && pilha->caracter[pilha->topo - 1] != '/'){
            pilha = empilha((double) expre[i], pilha);

          }
          else{
            printf("%c",(int) pilha->caracter[pilha->topo-1]);
            expressao[j++] = pilha->caracter[pilha->topo-1];
            pilha->topo--;
            pilha = empilha((double) expre[i], pilha);
          }
        } //end '*'

        else if(expre[i] == '+'){

          if(pilhaVazia(pilha) || pilha->caracter[pilha->topo-1] == '('){
            pilha = empilha((double) expre[i], pilha);
          }

          else{
            printf("%c",(int) pilha->caracter[pilha->topo-1]);
            expressao[j++] = pilha->caracter[pilha->topo-1];
            pilha->topo--;
            pilha = empilha((double) expre[i], pilha);
          }

        } //end '+'

        else if(expre[i] == '-'){
          if(pilhaVazia(pilha) || pilha->caracter[pilha->topo-1] == '('){
                pilha = empilha((double) expre[i], pilha);
            }

          else{
            printf("%c",(int) pilha->caracter[pilha->topo-1]);
            expressao[j++] = pilha->caracter[pilha->topo-1];
            pilha->topo--;
            pilha = empilha((double) expre[i], pilha);
          }
        } //end '-'

        else{
          printf("%c",expre[i]);
          expressao[j++] = expre[i];
        }
      }

      i++;

      if(expre[i] == '\0' || expre[i] == ')'){

        while(pilha->topo > 0 && pilha->caracter[pilha->topo - 1] != '(' ){
          printf("%c",(int) pilha->caracter[--pilha->topo]);
          expressao[j++] = pilha->caracter[pilha->topo];
        }

        if(pilha->caracter[pilha->topo - 1] == '(')
          --pilha->topo;
      }

  }

  expressao[j] = '\0';
  printf("\n");
  calcula_posfixa(expressao);
  liberaPilha(pilha);
}

void imprime_pilha(int i, p_nodo *pilha){

    printf("Modo calculadora\n");

  for(i; i > 0; --i)
      printf("%d. %.2lf\n",i,pilha->caracter[pilha->topo - i]);

}

void calculadora(){

  p_nodo *pilha = getNodo(pilha);
  int i,j,N,K;
  char num[10];
  j = 0;
  i = 0;

  printf("\nPilha Vazia!\n");

  while(scanf("%s",num) != EOF)
  {

    if(num[0] == 'q')
        return;

    double a = 0, b = 0, x = 0, N = 0, K = 0;

    if(pilhaVazia(pilha))
    {

      if(num[0] == '*' || num[0] == '/' || num[0] == '-' || num[0] == '+' || num[0] == 'c')
        printf("----------------Numero de operandos insuficiente---------\n");
      else{
        x = conv(num);
        //printf("%.2lf\n",x);
        pilha = empilha((double) x,pilha);
        printf("Modo calculadora\n");
        printf("%d. %.2lf\n",++i,(double) pilha->caracter[pilha->topo-1]);
      }

    }
    else
    {
      if(num[0] == '*')
      { // MULTIPLICAÇÃO
          if(num[1] == '!' && pilha->topo > 1)
          {
              while(pilha->topo > 1)
              {
                  a = (double) pilha->caracter[pilha->topo - 1];
                  b = (double) pilha->caracter[pilha->topo - 2];
                  pilha = desempilha(pilha);
                  pilha = desempilha(pilha);
                  pilha = empilha(b*a,pilha);
                  --i;
              }
              imprime_pilha(i,pilha);

          }

        else if(pilha->topo <= 1)
        {
            printf("----------------Numero de operandos insuficiente---------\n");
            imprime_pilha(i,pilha);
        }

        else
        {
            a = (double) pilha->caracter[pilha->topo - 1];
            b = (double) pilha->caracter[pilha->topo - 2];
            pilha = desempilha(pilha);
            pilha = desempilha(pilha);
            pilha = empilha(a*b,pilha);
            imprime_pilha(--i,pilha);
        }
    } //end MULTIPLICAÇÃO
      else if(num[0] == '+')
      { // SOMA
          if(num[1] == '!' && pilha->topo > 1)
          {
              while(pilha->topo > 1)
              {
                  a = (double) pilha->caracter[pilha->topo - 1];
                  b = (double) pilha->caracter[pilha->topo - 2];
                  pilha = desempilha(pilha);
                  pilha = desempilha(pilha);
                  pilha = empilha(a+b,pilha);
                  --i;
              }
              imprime_pilha(i,pilha);

          }

          else if(pilha->topo <= 1)
          {
              printf("----------------Numero de operandos insuficiente---------\n");
              imprime_pilha(i,pilha);
          }

          else
          {
              a = (double) pilha->caracter[pilha->topo - 1];
              b = (double) pilha->caracter[pilha->topo - 2];
              pilha = desempilha(pilha);
              pilha = desempilha(pilha);
              pilha = empilha(a+b,pilha);
              imprime_pilha(--i,pilha);
          }
      } //end SOMA
      else if(num[0] == '-')
      { // SUBTRAÇÃO
          if(num[1] == '!' && pilha->topo > 1)
          {
              while(pilha->topo > 1)
              {
                  a = (double) pilha->caracter[pilha->topo - 1];
                  b = (double) pilha->caracter[pilha->topo - 2];
                  pilha = desempilha(pilha);
                  pilha = desempilha(pilha);
                  pilha = empilha(b-a,pilha);
                  --i;
              }
              imprime_pilha(i,pilha);

          }

          else if(pilha->topo <= 1 && strlen(num) < 2)
          {
              printf("----------------Numero de operandos insuficiente---------\n");
              imprime_pilha(i,pilha);
          }
          else if(strlen(num) >= 2)
          {
              x = conv(num);
              pilha = empilha((double) x,pilha);
              imprime_pilha(++i,pilha);
          }
          else
          {
              a = (double) pilha->caracter[pilha->topo - 1];
              b = (double) pilha->caracter[pilha->topo - 2];
              pilha = desempilha(pilha);
              pilha = desempilha(pilha);
              pilha = empilha(b-a,pilha);
              imprime_pilha(--i,pilha);
          }
      } //end SUBTRAÇÃO
      else if(num[0] == '/')
      { //DIVISÃO
          if(num[1] == '!' && pilha->topo > 1)
          {
              while(pilha->topo > 1)
              {
                  a = (double) pilha->caracter[pilha->topo - 1];
                  b = (double) pilha->caracter[pilha->topo - 2];
                  pilha = desempilha(pilha);
                  pilha = desempilha(pilha);
                  pilha = empilha(b/a,pilha);
                  --i;
              }
              imprime_pilha(i,pilha);

          }
          else if(pilha->topo <= 1)
          {
              printf("----------------Numero de operandos insuficiente---------\n");
              imprime_pilha(i,pilha);
          }
          else
          {
              a = (double) pilha->caracter[pilha->topo - 1];
              b = (double) pilha->caracter[pilha->topo - 2];
              pilha = desempilha(pilha);
              pilha = desempilha(pilha);
              pilha = empilha(b/a,pilha);
              imprime_pilha(--i,pilha);
          }
      } //end DIVISÃO
      else if(num[0] == 'c')
      {
          N = pilha->caracter[pilha->topo - 1];
          desempilha(pilha);
          K = pilha->caracter[pilha->topo - 1];
          desempilha(pilha);

          i = N;

          while(N--)
            pilha = empilha(K,pilha);

          imprime_pilha(i,pilha);


      } //end 'C'
      else if(num[0] != '/' || num[0] != '+' || num[0] != '-' || num[0] != '*' || num[0] != 'c')
      {
        x = conv(num);
        pilha = empilha((double) x,pilha);
        imprime_pilha(++i,pilha);
      }
    }

    printf("->");
    j++;
  } //end while
  liberaPilha(pilha);
}

double conv(char *a){

    int aux = -1, j = 0, k = 0, at;
    char num[20];
    float c;

    for(int i = 0; i < strlen(a); ++i)
    {
        if(a[i] == '.')
            k=1;
        else
        {
            num[j] = a[i];
            j++;
        }

        if(k == 1)
            aux++;
    }

    at = atoi(num);
    c = (double) at;

    switch(aux){
        case 1:
            c = c/10;
        break;

        case 2:
            c = c/100;
        break;

        case 3:
            c = c/1000;
        break;
    }

    return c;
}

void calcula_posfixa(char *a){

    p_nodo *pilha = getNodo(pilha);
    int i, c = 0;
    double x,y;
    i = 0;

    while(a[i] != '\0')
    {

        if(a[i] == '+')
        {
            x = pilha->caracter[pilha->topo - 2];
            y = pilha->caracter[pilha->topo - 1];
            pilha = desempilha(pilha);
            pilha = desempilha(pilha);
            pilha = empilha(x+y,pilha);
        }
        else if(a[i] == '-')
        {
            x = pilha->caracter[pilha->topo -2];
            y = pilha->caracter[pilha->topo -1];
            pilha = desempilha(pilha);
            pilha = desempilha(pilha);
            pilha = empilha(x-y,pilha);
        }
        else if(a[i] == '*')
        {
            x = pilha->caracter[pilha->topo -2];
            y = pilha->caracter[pilha->topo -1];
            pilha = desempilha(pilha);
            pilha = desempilha(pilha);
            pilha = empilha(x*y,pilha);

        }
        else if(a[i] == '/')
        {
            x = pilha->caracter[pilha->topo -2];
            y = pilha->caracter[pilha->topo -1];
            pilha = desempilha(pilha);
            pilha = desempilha(pilha);
            pilha = empilha(x/y,pilha);

        }
        else if(a[i] != ' ' && a[i] != '+' && a[i] != '-' && a[i] != '*' && a[i] != '/' && a[i] != '\0'
        && a[i] != '.')
        {
            char aux[20];
            int k = 0;
            int j = i;
            double n;

            while(a[j] != ' ' && a[j] != '+' && a[j] != '-' && a[j] != '*' && a[j] != '/' && a[j] != '\0')
            {
                aux[k] = a[j];
                k++;
                j++;
            }

            aux[k] = '\0';
            i = j - 1;

            n = conv(aux);
            setbuf(stdin,NULL);
            pilha = empilha((double) n,pilha);

        }

        i++;
    } //end WHILE

    printf("%.2lf\n",pilha->caracter[pilha->topo - 1]);
    liberaPilha(pilha);
}
