#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    cin >> N;


    while(N--){
        int L, y, aux = 0;
        cin >> L;
        y = L;

        while(L--){
            string a;
            int j = 0;
            cin >> a;

            for(auto i:a)
            {
                aux += (int) i - 65;
                aux += y - (L + 1);
                aux += j;
                j++;
            }

        }
        cout << aux << endl;

    }

    return 0;
}
