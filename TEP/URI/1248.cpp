#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    cin >> N;
    getchar();

    while(N--)
    {
        string a,b,c;
        map <char,int> L;
        int v = 1;
        getline(cin,a);
        getline(cin,b);
        getline(cin,c);
        b += c;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        if(a.size() < b.size())
        {
            cout << "CHEATER" << endl;
            v = 0;
        }
        else
        {
            for(auto i:b)
            {
                if(a.find(i) == string::npos)
                {
                    cout << "CHEATER" << endl;
                    v = 0;
                    break;
                }
                else
                {
                    ++L[i];

                    if(L[i] > 1)
                    {
                        cout << "CHEATER" << endl;
                        v = 0;
                        break;
                    }
                }
            }
        }

        if(v)
        {
            for(auto i:a)
            {
                if(b.find(i) == string::npos)
                    cout << i;
            }
            cout << endl;
        }
    }

    return 0;
}
