#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define ll long long
void seive(void);
ll reverse(ll x);
ll primes[MAX/64];
bool on(ll x)	{return primes[x/64] & (1<<((x%64)/2));}
void mark(ll x)	{primes[x/64] |= (1<<((x%64)/2));}
bool isPrime(ll x);
//bool isPrime(ll n)	{return n>1 && (n==2 || ((n&1) && !on(n)));}
int main()
{
	ll n;
	//seive();
	while((scanf("%lld",&n)) == 1)
	{
		if(isPrime(n))
		{
			if(isPrime(reverse(n)) && n != reverse(n))
				printf("%lld is emirp.\n",n);
			else
				printf("%lld is prime.\n",n);
		}
		else
			printf("%lld is not prime.\n",n);
	}
	return 0;
}
bool isPrime(ll x)
{
	if(x==2 || x==3)	return true;
	if(x<4)	return false;
	if(!(x&1))	return false;
	for(ll i=3;i*i<=x;i+=2)
	{
		if(x%i==0)	return false;
	}
	return true;
}
void seive(void)
{
	for(ll i=3;i*i<=MAX;i+=2)
	{
		if(!on(i))
		{
			for(ll j=i*i;j*j<=MAX;j+= i+i)
			{
				mark(j);
			}
		}
	}
}
ll reverse(ll x)
{
	ll r,rev=0;
	while(x>0)
	{
		r = x%10;
		rev *= 10;
		rev += r;
		x /= 10;
	}
	return rev;
}
