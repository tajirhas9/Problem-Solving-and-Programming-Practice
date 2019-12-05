#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define RESET(a,b)	memset(a,b,sizeof(a))
#define lcm(a,b) (a*(b/gcd(a,b)))
#define gcd(a,b)	__gcd)(a,b)
typedef long long ll;
typedef string string;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<char> vs;
typedef set<ll> setl;
typedef set<string> sets;
typedef set<ll>::iterator setl_it;
typedef set<string>::iterator sets_it;
typedef vector<ll>::iterator vl_it;
typedef vector<string>::iterator vs_it;
struct func
{
	//this is a sample overloading function for sorting stl
	bool operator()(pii const &a, pii const &b)	
	{
		if(a.first==b.first)
			return (a.second<b.second);
		return (a.first>b.first);
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	ll i,j,k;
	bool foo=false,fo=false;
	vs s1,s2,s3;
	char a[123456],b[123456];
	scanf("%s %s",a,b);
	ll f=0;
	rep(i,0,strlen(a)-1)
	{
		if(i>0 && a[i]==a[i-1])	f++;
		else
		{
			fo = true;
		}
		
		s1.pb(a[i]);
		s3.pb(b[i]);
	}
	if(f==strlen(a)-1 && fo)
	{
		foo=true;
	}
	rep(i,0,strlen(b)-1)	s2.pb(b[i]);
	sort(s1.begin(),s1.end());
	reverse(s1.begin(),s1.end());
	//cout << "sorted" << endl;
	s3=s2;
	if(strlen(b)>strlen(a))		s3=s1;
	else
	{
		do
		{
			if(s3==s1)	break;
			if(s1[0]<s2[0])
			{
				s3=s1;
				break;
			}
			else
			{
				if(s1[0]>s2[0])	continue;
				else
				{
					i=0;
					while(s1[i]==s2[i] && i<strlen(a))	i++;
					if(i==strlen(a))	
					{
						s3=s1;
						break;
					}
					else if(s1[i]<s2[i])
					{
						s3=s1;
						break;
					}
					else continue;
				}
			}
			rep(i,0,s1.size()-1)	cout << s3[i];
			cout << endl;
		}
		while(prev_permutation(s1.begin(),s1.end()) && !foo);
	}
	rep(i,0,s1.size()-1)	cout << s3[i];
	return  0;
}













//?

