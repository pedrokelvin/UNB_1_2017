#include <bits/stdc++.h>

using namespace std;

typedef struct p{
  int i;
  float t;
  string nome;
}Dados;


int main(){

    list<Dados> d;
    Dados aux;

    aux.i = 10;
    aux.f = 3.0;
    aux.nome = "Pedro";

    d.push_back(aux);

  return 0;
}
