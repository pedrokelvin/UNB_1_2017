

/*APRENDENDO A USAR "PAIR" COM VECTOR E ORDENAR DE ACORDO COM QUAISQUER PARAMETROS*/

#include <bits/stdc++.h>

using namespace std;

using is = pair<int,string>;

bool comp(is a, is b);

int main(){

  vector<is> v;
  string b;
  int a;

  while(cin >> a >> b)
    v.push_back(is(a,b));

    cout << "---------------" << endl;

  sort(v.begin(),v.end(),comp);

  for(auto i : v)
    cout << i.first << " " << i.second << endl;

  return 0;
}

bool comp(is a, is b){

  if(a.first == b.first)
    return a.second > b.second;
  else
    return a.first > b.first;
}
