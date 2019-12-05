#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000
#define ll long long
ll primes[MAX/64+2];
void seive(void);
bool on(ll x) {return primes[x/64] & (1<<(x%64)/2);}
void mark(ll x)	{primes[x/64] |= (1<<(x%64)/2);}
bool isPrime(ll n) {return n>1 && (n==2 || ((n&1)  && !on(n)));}
int main()
{
	seive();
	for(ll i=2;i<=MAX;i++)
		if(isPrime(i))	printf("%lld\n",i);
	return 0;
}
void seive(void)
{
	for(ll i=3;i*i<=MAX;i+=2)
	{
		if(!on(i))
		{
			for(ll j = i*i; j<=MAX;j+=i+i)
			{
				mark(j);
			}
		}
	}
}
