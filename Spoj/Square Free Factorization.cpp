#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
void getPrimeFactors(ll x);
void reset(void);
vector<ll> prime_factors;
ll two=0,other=0;
int main()
{
	int T;
	ll x,factor;
	scanf("%d",&T);
	while(T--)
	{
		reset();
		scanf("%lld",&x);
		getPrimeFactors(x);
		if(two < 2)
			factor = other;
		else
		{
			factor = two+other;
			factor -= 2*other;
			factor += other;
		}
		//for(ll i=0;i<prime_factors.size();i++)	printf("%lld ",prime_factors[i]);
		//cout << endl;
		printf("%lld\n",factor);
	}
	return 0;
}
void getPrimeFactors(ll x)
{
	for(ll i = 2;i*i<=x;i++)
	{
		while(x%i==0)
		{
			prime_factors.push_back(i);
			x /= i;
			if(i==2)	two++;
			else 	other++;
		}
	}
	if(x > 1)
	{
		prime_factors.push_back(x);
		(x==2) ? two++ : other++;
	}
}
void reset(void)
{
	prime_factors.clear();
	two=0;
	other=0;
}
