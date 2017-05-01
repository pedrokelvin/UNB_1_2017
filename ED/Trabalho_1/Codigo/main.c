/**
* @file main.c
* @author Pedro Kelvin
* @date 1 Maio 2017
* @brief Arquivo principal para a execução do programa de conversão de uma expressão da
* forma infixa para a forma pós-fixa. Bem como a reprensentação de uma calculadora
* através do uso de pilha.
* Trabalho proposta para a disciplina de Estrutura de Dados - Unb
*/

#include<stdio.h>
#include<stdlib.h>
#include "declaracoes.h"

/**
* @brief A função principal abaixo se encarrega da interação com o usuário, onde
* ele deve selecionar a opção que deseja entre as duas do programa: Modo expressão
* ou Modo calculadora.
*/

int main(){

  int valida,op;
  char *expre;
  expre = (char *) malloc(sizeof(char)*100);

  printf("Selecione a opcao desejada:\n1.Modo Expressao\n2.Modo calculadora\n");

  while(scanf("%d",&op) != EOF)
  {

    switch(op)
    {

      case 1:
        getchar();
        printf("\nModo expressao\n");
        scanf("%[^'\n']",expre);

        if(expre[0] != 'q')
        {
            valida = validacao(expre);

            if(valida)
                imprimePosfixa(expre);
        }
      break;

      case 2:
        calculadora();
      break;

      default:
        printf("Digite um valor correto\n");
      break;
    }

    printf("\nSelecione a opcao desejada:\n1.Modo Expressao\n2.Modo calculadora\n");
  }

  return 0;
}
