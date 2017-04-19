#include<bits/stdc++.h>

using namespace std;

int main(){

  int C,B,S,F;
  C = F = S = B = 0;
  char c = '0';

  while(c != EOF){

    while(c != '\n'){

        if(c == 'C')
          C++;
        else if(c == 'F')
          F++;
        else if(c == 'S')
          S++;
        else if(c == 'B')
          B++;

      c = getchar();
    }

    B = (B+S)/2;
    C = (C+F)/2;

    cout << B + C << endl;

    B = 0;
    S = 0;
    F = 0;
    C = 0;
    c = '0';
  }

  return 0;
}
