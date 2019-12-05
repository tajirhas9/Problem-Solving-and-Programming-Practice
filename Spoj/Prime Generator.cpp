#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(ll x);
int main()
{
	ll T,s,d;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld",&s,&d);
		if(s==2)
		{
			printf("%lld\n",s);
			s++;
		}
		else
		{
			if(!(s&1))	s++;
		}
		for(ll i=s;i<=d;i+=2)
		{
			if(isPrime(i))	printf("%lld\n",i);
		}
		//printf("\n");
	}
	return 0;
}
bool isPrime(ll x)
{
	ll y = sqrt(x);
	if(x==2)	return  true;
	if(!(x&1) || x<2)	return false;
	for(ll i=3;i<=y;i+=2)
	{
		if(x%i==0)	return false;
	}
	return true;
}	
