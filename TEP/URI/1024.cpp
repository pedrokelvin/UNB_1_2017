#include <bits/stdc++.h>

using namespace std;

int main(){

  int i, j = 0, m;
  cin >> i;

  getchar();
  
  while(i){
      string nome;
      getline(cin,nome);

      while(nome[j] != '\0'){
        if((int) nome[j] >= 65 && (int) nome[j] <= 122){
          if((int) nome[j] > 96 || (int) nome[j] <= 90)
            nome[j] = (int) nome[j] + 3;
        }

        j++;
      }
      m = nome.length();

      if(m%2 == 0)
        m = nome.length()/2;
      else if(m%2 != 0)
        m = nome.length()/2 + 1;

      for(int k = 0; k<m; ++k)
        nome[k] = (int) nome[k] - 1;

      for(int x = nome.length()-1; x >= 0; x--)
        cout << nome[x];

    j=0;
    i--;
    cout << endl;
  }

  return 0;
}
