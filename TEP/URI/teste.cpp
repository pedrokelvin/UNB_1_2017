#include <bits/stdc++.h>
using namespace std;

int main(){

    char c[10];
    string a = "Pedro";

    c[0] = a[0];
    c[1] = a[4];
    c[3] = '\0';

    for(auto i:c)
        cout << i << endl;
}
