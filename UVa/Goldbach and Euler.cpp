#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
#define MAX 100000002
void seive(void);
ll prime[MAX/64+2];
bool on(ll x)		{return prime[x/64] & (1<<((x%64)/2));}
void mark(ll x)		{prime[x/64] |= (1<<((x%64)/2));}
bool isPrime(ll n)	{ return n>1 && (n==2 || (n&1)) && !on(n);}
vector<ll> primeSet;
int main()
{
	ll x;
	memset(prime,0,sizeof(prime));
	seive();
	while((scanf("%lld",&x)) != EOF)
	{
		bool done = false;
		ll a,b;
		for(ll i=2;i<=x/2;i+=2)
		{
			if(isPrime(i) && isPrime(x-i))
			{
				a = i; b = x-i;
				done = true;
			}
			if(i==2)	--i;
		}
		if(done)	printf("%lld is the sum of %lld and %lld.\n",x,a,b);
		if(!done)	printf("%lld is not the sum of two primes!\n",x);
	}
	return 0;
}
void seive(void)
{
	for(ll i=3;i*i<MAX;i+=2)
	{
		if(!on(i)) // if prime
		{
			for(ll j = i*i;j<= MAX;j += i+i)
			{
				mark(j);
			}
		}
	}
}
