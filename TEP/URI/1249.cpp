#include <bits/stdc++.h>

using namespace std;

int main(){

    map <char,int> m1,m2;
    string a = "abcdefghijklmnopqrstuvwxyz";
    string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string nome;
    int m = 1;

    for(auto i:a){
        m1[m] = i;
        m++;
    }
    m = 1;

    for(auto i:b)
    {
        m2[m] = i;
        m++;
    }


    while(getline(cin,nome))
    {
        int c;

        for(auto i:nome)
        {
            if((int)i >= 65 && (int) i <= 90)
            {
                c = (int) i - 64;
                if((c + 13)%26 == 0)
                    cout << (char) m2[c + 13];
                else
                    cout << (char) m2[(c + 13)%26];
            }
            else if((int) i >= 97 && (int) i <= 122)
            {
                c = (int) i - 96;

                if((c + 13)%26 == 0)
                    cout << (char) m1[c + 13];
                else
                    cout << (char) m1[(c + 13)%26];
            }
            else
                cout << (char) i;
        }

        cout << endl;

    }


    return 0;
}
