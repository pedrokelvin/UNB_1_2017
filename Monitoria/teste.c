#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        float X1, X2;
        char O;
        scanf("%f%c%f", &X1, &O, &X2);

        if(O == 43)
        {
            printf("%.6f\n", X1 + X2);
        }
}
