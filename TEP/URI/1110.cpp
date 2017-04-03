#include <bits/stdc++.h>

using namespace std;

void imprime(queue<int> f1, queue<int> f2);

int main(){

  queue<int> f1,f2;
  int i,n = 1;



  cin >> i;

  while(i){
    while(n<=i){
      f1.push(n);
      n++;
    }

    while(f1.size() > 1){
      f2.push(f1.front());
      f1.pop();

      if(f1.size() > 1){
        f1.push(f1.front());
        f1.pop();
      }
    }

    imprime(f1,f2);

    n = 1;

    while(!f1.empty())
      f1.pop();
    while(f2.empty())
      f2.pop();
    cin >> i;
  }

  return 0;
}

void imprime(queue<int> f1, queue<int> f2){

  cout << "Discarded cards: ";

  if(f2.empty()){
    cout << endl;
    cout << "Remaining card: " << f1.front() << endl;
  }
  else if(f2.size() > 0){
    cout << f2.front() << endl;
    cout << "Remaining card: " << f1.front() << endl;
  }

}
