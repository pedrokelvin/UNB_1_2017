#include <iostream>

using namespace std;

int main(){
  
  int h1,h2,R;

  cin >> h1 >> h2;

  if(h1 >= h2){
    R = 24 - h1 + h2;
  }
  else if(h1 < h2){
    R = h2 - h1;
  }

  cout << "O JOGO DUROU " << R << " HORA(S)"<< endl;

  return 0;
}
