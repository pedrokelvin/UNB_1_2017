#include <bits/stdc++.h>

using namespace std;

int main(){

    string a, b;

    while(cin >> a >> b){

        string c;
        set<int> tam;

        for(int i = 0; i < a.size() ; i++)
        {
            for(int j = 0; j < b.size(); j++)
            {
                if(a[i] == b[j])
                {
                    int x = i, y = j, k = 0;

                    while(a[x] == b[y] && a[i] != '\0' && b[i] != '\0')
                    {   
                        k++;
                        x++;
                        y++;
                    }

                tam.insert(-k);
                i += k;
                j += k;
                }
            }
        }

        for(auto i:tam)
        {
            cout << i << endl;
            break;
        }

    }

    return 0;
}
