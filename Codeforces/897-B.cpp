#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void g_palindrome(ll k);
ll c_palindrome(ll n);
set<ll>p;
int main()
{
	ll k,m,sum=0;
	cin >> k >> m;
	g_palindrome(k);
	set<ll>::iterator it;
	for(it = p.begin(); it != p.end();it++)
	{
		sum = (sum%m+(*it)%m)%m;
	}
	cout << sum << endl;
	return 0;
}
void g_palindrome(ll n)
{
	ll number,i=1;
	while((number=c_palindrome(i)))
	{
		p.insert(number);
		i++;
		if(p.size() >= n)	break;
	}
}
ll c_palindrome(ll n)
{
	ll palin;
	palin=n;
	while(n>0)
	{
		palin *=10;
		palin += n%10;
		n /= 10;
	}
	return palin;
}
