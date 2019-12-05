#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,n,kobayashi=0,tohru=0;
	cin >> t;
	while(t--)
	{
		cin >> n;
		while(n--)
		{
			cin >> a;
			if(a==1)	kobayashi++;
			else if(a==2)	tohru++;
			else if(a==4)
			{
				kobayashi++;
				tohru++;
			}
			else
			{
				kobayashi--;
				tohru--;
			}
		}
		if(kobayashi == tohru)	cout << "Draw" << endl;
		else if(kobayashi > tohru)	cout << "Kobayashi" << endl;
		else 	cout << "Tohru" << endl;
		kobayashi=0;
		tohru=0;
	}
	return 0;
}

