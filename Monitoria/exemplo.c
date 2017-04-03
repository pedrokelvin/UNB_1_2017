#include <stdio.h>

int main(){
	
	
	int a,b,resultado;
	
	scanf("%d %d",&a,&b);

	resultado = a + b;
	
	printf("A soma de a e b é igual a 10?\n");	
	
	if(resultado == 10){
		printf("Sim, é 10\n");	
	}else{
		printf("nao\n");		
		printf("Na verdade, o resultado é: %d\n",resultado);		
	}
			
	return 0;
}
