#include <stdio.h>
#include <stdlib.h>

int main(){

  long int a,b,c, maiorAB, maiorBC;
  
  scanf("%ld %ld %ld",&a,&b,&c);

  maiorAB = (a + b + abs(a -b))/2;
  maiorBC = (maiorAB + c + abs(maiorAB - c))/2;

  printf("%ld eh o maior\n",maiorBC);

  return 0;
}
