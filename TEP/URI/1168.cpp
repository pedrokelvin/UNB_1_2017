#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;

    cin >> N;

    while(N--)
    {
        string a;
        int V = 0;
        cin >> a;

        for(auto i:a)
        {
            if(i == '2' || i == '3' || i == '5' )
            {
                V += 5;
            }else if(i == '4')
            {
                V += 4;
            }else if(i == '6' || i == '9' || i == '0')
            {
                V += 6;
            }else if(i == '1')
            {
                V += 2;
            }else if(i == '7')
            {
                V += 3;
            }else if(i == '8')
            {
                V += 7;
            }
        }

        cout << V << " leds" << endl;
    }

    return 0;
}
