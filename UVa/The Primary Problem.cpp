#include <bits/stdc++.h>
using namespace std;
#define ll long long
void seive(void);
bool prime[1000005];
int main()
{
	ll x;
	memset(prime,false,sizeof(prime));
	seive();
	while(1)
	{
		bool done = false;
		scanf("%lld",&x);
		if(x==0)	break;
		printf("%lld:\n",x);
		for(ll i=2;i <= x/2;i++)
		{
			if(!prime[i] && !prime[x-i])
			{
				printf("%lld+%lld\n",i,x-i);
				done = true;
				break;
			}
		}
		if(!done)	printf("NO WAY!\n");
	}
	return 0;
}
void seive(void)
{
	for(ll i=2;i*i<=1000005;i++)
	{
		if(prime[i] == false) // if prime
		{
			for(ll j = i*i;j< 1000005;j += i)
			{
				prime[j] = true;
			}
		}
	}
}
