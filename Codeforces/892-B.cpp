#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[1000005],j,i,c;
bool b[1000005];
int main()
{
	
	cin >> n;
	c=0;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		b[i] = true;
		for(j=i-1;j>=(i-a[i]) && j>=0;j--)
			b[j] = false;
	}
	for(i=0;i<n;i++)
	{
		if(b[i])	c++;
	}
	cout << c << endl;
	return 0;
}
