#include <bits/stdc++.h>

using namespace std;

typedef struct S{
  string nome;
  int valor;

}Nome;

bool comp(string a, string b);

int main(){

  list<Nome> n;

  n.push_back("Pedro",10);
  n.push_back("Pedrodasdas");
  n.push_back("Pedr");
  n.push_back("Pedrasdddddddad");
  n.push_back("Pe");

  n.sort(comp);

  for(auto i : n)
    cout << i << endl;

  return 0;
}

bool comp(string a, string b){
  return a.size() > b.size();

}
