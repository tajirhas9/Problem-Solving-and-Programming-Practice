#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,i,a,free=0,untreated=0;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> a;
		if(a>=0)
		{
			free += a;
		}
		else
		{
			if(free>0)	free--;
			else 		untreated++;
		}
	}
	cout << untreated << endl;
	return 0;
}
