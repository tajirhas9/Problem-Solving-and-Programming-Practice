#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	long long t,remain[100005],capacity[100005],total=0,m1=0,m2=0;
	cin >> t;
	for(ll i=1;i<=t;i++)	
	{
		cin >> remain[i];
		total += remain[i];
	}
	for(ll i=1;i<=t;i++)
	{
		cin >> capacity[i];
		if(capacity[i] > m1)
		{
			m2 = max(m2,m1);
			m1 = capacity[i];
		}
		else if(capacity[i] > m2)
		{
			m2 = capacity[i];
		}
	}
	ll tCap;
	tCap = m1+m2;
	//cout << total << " " << tCap << endl;
	(total <= tCap) ? cout << "YES" << endl : cout << "NO" << endl;
	return 0;
}
