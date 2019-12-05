#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000000000000000
#define ll unsigned long long
ll power(ll x);
ll squareMod(ll x);
bool millerRabin(ll d,ll n,ll r);
bool isPrime(ll x);
int main()
{
	ll T,x;
	scanf("%llu",&T);
	while(T--)
	{
		scanf("%llu",&x);
		if(isPrime(x))	printf("YES\n");
		else 	printf("NO\n");
	}
	return 0;
}
ll power(ll x,ll y,ll m)
{
	ll r=1;
	x %= m;
	while(y>0)
	{
		if(y&1)	r  = (r*x)%m;
		y = y>>1;
		x = (x*x)%m;
	}
	return r;
}
ll squareMod(ll a,ll m)
{
	ll r=0;
	ll x = a%m;
	ll y = a;
	while(y>0)
	{
		if(a&1)	r = (r+x)%m;
		x = (x<<1)%m;
		y >>= 1;
	}
	return r;
}
bool isPrime(ll x)
{
	if(x==2 || x==3)	return true;
	if(x<4)	return false;
	if(!(x&1) ||  x%3==0)	return false;
	ll d = x-1;
	ll r=0;
	while(d%2==0)
	{
		d >>= 2;
		r++;
	}
	ll k=0;
	cout << "d : " << d << " r: " << r << endl; 
	while(k++ < 20)
	{
		if(millerRabin(d,x,r)==false)	return false;
	}
	return true;
}
bool millerRabin(ll d,ll n,ll r)
{
	ll a;
	a = rand()%(n-4)+2;
	ll x;
	cout << "a: " << a << endl;
	x = power(a,d,n);
	cout << x << endl;
	if(x==1 || x==n-1)	return true;
	while(d != n-1)
	{
		x = squareMod(x,n);
		cout << x << endl;
		d <<= 1;
		if(x==1)	return false;
		if(x==n-1)	return true;
	}
	return false;
}
