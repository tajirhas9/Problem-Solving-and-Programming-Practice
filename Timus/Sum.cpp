#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,n,sum=0;
	cin >> n;
	if(n<=0)
	{
		for(i=n;i<=1;i++)
		{
			sum += i;
		}
	}
	else
	{
		for(i=n;i>=1;i--)
			sum += i;
	}
	cout << sum << endl;
	return 0;
}
