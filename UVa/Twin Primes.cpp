#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
void seive(void);
vector< pair<ll,ll> > twins;
bool primes[20000005];
int main()
{
	seive();
	ll x;
	while((scanf("%lld",&x)) != EOF)
	{
		x--;
		printf("(%lld, %lld)\n",twins[x].first,twins[x].second);
	}
	return 0;
}
void seive(void)
{
	memset(primes,false,sizeof(primes));
	for(ll i=2;i*i<=20000004;i++)
	{
		if(!primes[i])
		{
			for(ll j=i*i;j<20000005;j+=i)
			{
				primes[j] = true;
			}
		}
	}
	for(ll i=5;i<20000005;i++)
	{
		if(!primes[i] && !primes[i-2])
			twins.push_back(make_pair(i-2,i));
	}
}
