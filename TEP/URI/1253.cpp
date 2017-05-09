#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;

    cin >> N;
    while(N--)
    {
        string a,b = "";
        int m,M;

        cin >> a >> m;

        for(auto i:a)
        {
            M = m;
            if((int) i-M < 65)
            {
                M = M - (i - 65);
                i = (char ) (91);
            }

            i = (char) i - M;
            b += i;
        }

        cout << b << endl;
    }

    return 0;
}
