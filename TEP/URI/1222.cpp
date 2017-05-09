#include <bits/stdc++.h>
using namespace std;

int main(){

  while(1){
    string palavra;
    int N, L, C, R, x = 0;

    scanf("%d %d %d",&N,&L,&C);

    while(N--){
      cin >> palavra;
      x += palavra.size();
    }

    cout << "x e " << x << endl;

    if(x%C != 0)
      R = x/C + 1;
    else
      R = x/C;



  }

  return 0;
}
