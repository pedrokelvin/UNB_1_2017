#include<bits/stdc++11.h>

using namespace std;

int main(){

    int N;

    while(N--)
    {
        int k = 0, j = 0;
        string a = "one", b = "two", c = "three";
        string d;
        cin >> d;

        if(d.size() > 3)
            cout << "3" << endl;
        else
        {
            for(auto i:d)
            {
                if(a.find(i) != string::npos)
                    k++;
            }
        }

        if(j > 1)
            cout << "2";
        else if(k > 1)
            cout << "1";
    }

    return 0;
}
