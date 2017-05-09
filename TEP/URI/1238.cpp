#include <bits/stdc++.h>

using namespace std;

int main(){

	int i;

	cin >> i;

	while(i--)
	{
		string a,b;
		int x,A,B,j;
		cin >> a >> b;
		j = 0;

		A = a.size();
		B = b.size();

		if(A < B)
			x = A;
		else
			x = B;

		for(int k = 0; k < x; k++)
		{
				cout << a[k];	
				cout << b[k];
				j = k;
		}
		j += 1;


		if(A > B)
		{
			while(a[j] != '\0')
			{
				cout << a[j++];
			}
		}
		else
		{
			while(b[j] != '\0')
			{
				cout << b[j++];
			}
		}

		cout << endl;
	}

	return 0;
}
