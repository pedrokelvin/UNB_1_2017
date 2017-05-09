#include<bits/stdc++.h>

using namespace std;


int main(){

    int n;
    string num;

    cin >> n >> num;

    while(num != '0' && n != '0'){
        string aux = "";
        int j = 0;
        
        for(auto i:num){
            if(n != i)
                aux += i;
        }

        if(aux == "")
            cout << '0' << endl;

    }

  return 0;
}
