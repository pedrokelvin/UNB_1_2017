#include<bits/stdc++.h>

using namespace std;

int main(){

  string text = "ABCAB";
  string pat = "ABC";
  int count = 0;

  
  if(pat.size() == 1){

    for(int i = 0; i < text.size(); ++i)
      if(text[i] == pat[i])
        count++;
  }
  else{

    for(int i = 0; i < text.size()-pat.size() + 1; ++i){
      int hits = 0;

      for(int j = 0; j < pat.size(); j++){
        if(pat[j] == text[i+j])
          hits++;
        else
          break;
      }
      if(hits == pat.size())
        count++;
    }
  }
  cout << count << endl;

  return 0;
}
