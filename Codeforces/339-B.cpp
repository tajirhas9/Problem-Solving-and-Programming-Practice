#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,m,i,a[100000],steps=0,currentPos=1;
	cin >> n >> m;
	for(i=0;i<m;i++)
	{
		cin >> a[i];
		if(a[i] >= currentPos)
		{
			steps += a[i]-currentPos;
			currentPos = a[i];
		}
		else
		{
			steps += (n-currentPos)+a[i];
			currentPos = a[i];
		}
	}
	cout << steps << endl;
	return 0;
}
