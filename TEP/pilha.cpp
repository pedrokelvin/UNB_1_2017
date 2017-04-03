#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

  int a,n, aux = 0, *v;
  char c = 'a';
  stack<char> d;

  cin >> n;
  a = n;
  v = (int *) malloc(sizeof(int)*n);

  while(n){

    while(c != '\n'){
      cin >> c;

      if(c == '<')
        d.push(c);

      if(c == '>'){
        d.pop();
        aux++;
      }
      cout << "oi" << endl;
    }
      v[n] = aux;
      cout << v[n] << endl;
      n--;
      aux = 0;

    }

    for(int i = 0; i < a; i++)
      cout << v[i] << endl;

  return 0;
}
