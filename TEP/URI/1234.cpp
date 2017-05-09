#include <bits/stdc++.h>

using namespace std;

int main(){

    string nome;

    while(getline(cin,nome))
    {
        int i, j;
        j = 0;
        i = 0;


        while(nome[i] != '\0')
        {

            if(nome[i] != ' ')
            {

            if(j == 0 && nome[i] >= 97)
                nome[i] = toupper(nome[i]);
            else if(i > 0 && j == 1)
                nome[i] = tolower(nome[i]);
            else if(j == 2)
                nome[i] = toupper(nome[i]);

            if(nome[i] >= 97)
                j = 2;
            else
                j = 1;
            }

            i++;
        }

        cout << nome << endl;
    }

    return 0;
}
