#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[123456],b[123456],i,c[123456];
int main()
{
	int n;
	cin >> n;
	for(i=0;i<n;i++)	cin >> a[i];
	sort(a,a+n);
	cin >> m;
	for(i=0;i<m;i++)
	{	
		ll m;
		cin >> m;
		c[i] = max(0,(int)(upper_bound(a,a+n,m)-a));
	}
	for(i=0;i<m;i++)	cout << c[i] << endl;
	return 0;
}
