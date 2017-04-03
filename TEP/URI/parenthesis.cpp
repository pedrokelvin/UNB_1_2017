#include <bits/stdc++.h>

using namespace std;

int main(){

  stack<char> p;
  char c;
  int n = 1;



  while(c != EOF){
    c = getchar();

    if(c == '('){
      p.push(c);
    }
    else if(c == ')'){

      if(p.empty())
        p.push(c);
      else if(!p.empty() && p.top() == '(')
        p.pop();

    }
    else if(c == '\n'){

        if(p.empty())
          cout << "correct" << endl;
        else
          cout << "incorrect" << endl;

        while(!p.empty())
          p.pop();
    }

  }

  return 0;
}
