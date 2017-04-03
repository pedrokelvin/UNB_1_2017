#include <bits/stdc++.h>

using namespace std;

int main(){

  stack<char> p;
  int n,count = 0;
  char c;

  cin >> n;
  c = getchar();

  while(n){

    c = getchar();

    if(c == '<'){
      p.push(c);
    }
    else if(c == '>' && !p.empty()){
      p.pop();
      count++;
    }
    else if(c == '\n'){

      while(!p.empty()){
        p.pop();
      }

      n--;
      cout << count << endl;
      count = 0;
    }
  }

  return 0;
}
