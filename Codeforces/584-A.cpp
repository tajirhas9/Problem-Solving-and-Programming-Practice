#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,t;
char a[105];
void genNum(ll n);
ll findRem(void);
void increaseNum(void);
bool check(void);
int main()
{
	cin >> n >> t;
	genNum(n);
	while(check())
	{
		if(findRem()==0)	{ cout << a << endl; return 0;}
		else 				increaseNum();
	}
	cout << -1 << endl;
	return  0;
}
void genNum(ll n)
{
	ll i=0;
	a[i] = '1';
	for(i=1;i<n;i++)	a[i] = '0';
	a[i] = '\0';
}
ll findRem(void)
{
	ll rem=0,i=0;
	while(i<n)
	{
		if(rem>=t)
			rem %= t;
		else
		{
			rem *= 10;
			rem += (a[i++]-'0');
		}
	}
	return rem%t;
}
void increaseNum()
{
	ll i = n-1,carry=1;
	do
	{
		ll num;
		num = a[i]-'0';
		if(num==9 && carry>0)
		{
			a[i] = '0';
			carry = 1;
			i--;
		}
		else
		{
			a[i] = num+carry+'0';
			carry=0;
			i--;
		}
	}
	while(i>=0 && carry);
}
bool check(void)
{
	ll i;
	if(a[0]=='0')	return false;
	for(i=0;i<n;i++)
	{
		if(a[i]=='9')	continue;
		else 			return true;
	}
	if(a[0]=='9' && n==1)	return true;
	return false;
}
