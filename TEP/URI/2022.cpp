#include <bits/stdc++.h>

using namespace std;

using is = pair<int, float>;

#define v1 first.first
#define v2 first.second
#define v3 second

bool comp(pair<is,char *> x, pair<is,char *> y);

int main(){

  string nome;
  char c[100], d;
  int n, a;
  float b;
  vector<pair<is,char *>> v;

  cin >> nome >> n;

  while(n--){
    d = getchar();
    scanf("%[^\n]",c);
    cin >> b >> a;
    v.push_back(make_pair(is(a,b),c));
  }

  sort(v.begin(),v.end(),comp);
  cout << "Lista de " << nome << endl;
  for(auto i:v){
    cout << i.v3;
    printf(" - R$%.2f\n",i.v2);
  }

  return 0;
}

bool comp(pair<is,char *> x, pair<is,char *> y){

  if(x.v1 == y.v1)
    return x.v2 < y.v2;
  else if(x.v2 == y.v2)
    return x.v3 < y.v3;
  else
    return x.v1 > y.v1;
}
