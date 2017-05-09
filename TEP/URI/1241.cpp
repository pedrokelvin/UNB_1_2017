#include <bits/stdc++.h>

using namespace std;

int main(){

    int i;
    cin >> i;

    while(i--){
        string A,B;
        int x, y, j;
        j = 1;
        cin >> A >> B;

        if(B.size() > A.size())
            cout << "nao encaixa" << endl;
        else
        {
            x = B.size() - 1;
            y = A.size() - 1;

            for(int k = x; k >= 0; --k)
            {
                if(B[k] != A[y--])
                {
                    cout << "nao encaixa" << endl;
                    j = 0;
                    break;
                }
            }

            if(j == 1)
                cout << "encaixa" << endl;
        }

    }

    return 0;
}
