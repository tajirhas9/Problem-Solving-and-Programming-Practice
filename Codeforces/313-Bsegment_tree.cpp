#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],n,i,l,r,mid;
int main()
{
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	l = (ll)(upper_bound(a,a+n,(a[n-1]/2))-a);
	cout << n-l << endl;
	return  0;
}
