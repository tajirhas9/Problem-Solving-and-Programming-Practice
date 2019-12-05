#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll n,m,b[123456];
pii a[123456];
int main()
{
	ll start=1;
	cin >> n;
	for(ll i=0;i<n;i++)
	{
		ll x;
		cin >> x;
		a[i].first = start;
		a[i].second = start+x-1;
		start += x;
	}
	cin >> m;
	for(ll i=0;i<m;i++)
		cin >> b[i];
	for(ll i=0;i<m;i++)
	{
		ll l=0,r=n-1,mid;
		while(l<r)
		{
			mid = (l+r+1)>>1;
			if(b[i]>=a[l].first && b[i]<=a[l].second)	{ cout << l+1 << endl; break; }
			else if(b[i]>=a[r].first && b[i]<=a[r].second)	{ cout << r+1 << endl; break; }
			else if(b[i]>=a[mid].first && b[i]<=a[mid].second) { cout << mid+1 << endl; break; }
			else if(b[i]>a[mid].first)	l = mid;
			else if(b[i]<a[mid].second)	r = mid;	
		}
	}
	return 0;
}
