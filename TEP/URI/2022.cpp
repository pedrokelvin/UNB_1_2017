#include <bits/stdc++.h>

using namespace std;

using is = pair<long long, long long>;

#define v1 first.first
#define v2 first.second
#define v3 second

int main(){

  string nome;
  char d;
  int n;
  long long a, b, c;

  while(cin >> nome >> n){
    vector<pair<is,string>> v;

    while(n--){
      string gift;
      getchar();
      getline(cin,gift);
      scanf("%lld.%lld %lld",&a,&b,&c);
      v.push_back(make_pair(is(-c,a*100 + b),gift));
    }

    sort(v.begin(),v.end());

    cout << "Lista de " << nome << endl;
    for(auto i:v)
      printf("%s - R$%lld.%02lld\n",i.v3.c_str(), i.v2/100, i.v2%100);

    cout << endl;
  }

  return 0;
}
