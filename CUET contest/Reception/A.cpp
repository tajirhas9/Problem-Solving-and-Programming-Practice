#include <bits/stdc++.h>
using namespace std;
#define cin(x) scanf("%lld",&x)
#define cout(x) printf("%lld\n",x)
typedef long long ll;
bool palindrome(ll n);
string s;
int main()
{
	ll T,n;
	cin(T);
	while(T--)
	{
		cin(n);
		do
		{
			n++;
		}
		while(!palindrome(n));
		cout(n);
	}
	return 0;
}
bool palindrome(ll n)
{
	ll temp,r,rem=0;
	temp = n;
	while(temp>0)
	{
		r = temp%10;
		rem *= 10;
		rem += r;
		temp /= 10;
	}
	if(rem==n) return true;
	else
	{
		 return false;
	}
	
}
