#include <stdio.h>
#include <stdlib.h>

int main(){
    int* ptr;

    ptr = (int *) malloc(sizeof(int));

    *ptr = 4;

    char* ptr2 = (char *) ptr;

    printf("valor: %d\n", *ptr);
    printf("Endereço armazenado: %p\n", ptr);
    printf("Endereço de ptr: %p\n ", &ptr);

    ptr2[0] = 'z';
    ptr2[1] = 'w';
    2[ptr2] = 'e';
    ptr2[3] = 'q';

    printf("Valores char: \n");
    printf("%c\n", ptr2[0]);
    printf("%c\n", ptr2[1]);
    printf("%c\n", ptr2[2]);
    printf("%c\n", ptr2[3]);

    printf("Valor inteiro: %d \n", *ptr);



    return 0;
}






