#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll fact(ll n,ll m);
int main()
{
	ll n,m;
	while((scanf("%llu %llu",&n,&m))==2)
	{
		if(fact(n,m)==0)	printf("%lld divides %lld!\n",m,n);
		else 				printf("%lld does not divide %lld!\n",m,n);
	}
	return 0;
}
ll fact(ll n,ll m)
{
	if(n==0)	return 0;
	if(n==1)	return 1;
	return ((n%m)*(fact(n-1,m)%m))%m;
}
