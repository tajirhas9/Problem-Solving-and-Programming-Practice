#include <bits/stdc++.h>
using namespace std;
long long n,x,a[100005];
int main()
{
	long long c=0;
	cin >> n >> x;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		c += a[i];
	}
	if((c+(n-1)) == x)	cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
