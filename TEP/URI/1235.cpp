#include <bits/stdc++.h>

using namespace std;

int main(){

    int i;

    cin >> i;
    getchar();

    while(i--){
        string um = "", dois = "", nome;

        getline(cin,nome);

        for(int k = 0; k < nome.size()/2; k++)
            um += nome[k];

        for(int k = nome.size()/2; k < nome.size(); k++)
            dois += nome[k];

        for(int k = um.size() - 1; k >= 0; --k)
            cout << um[k];

        for(int k = dois.size() - 1; k >= 0; --k)
            cout << dois[k];

        cout << endl;
    }

    return 0;
}
