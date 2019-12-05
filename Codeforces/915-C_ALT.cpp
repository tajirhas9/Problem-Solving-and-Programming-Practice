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
	ll i,j,k=-1;
	vs s1,s2,s3;
	char a[123456],b[123456],c[1234567];
	bool ch[123456],foo=false;
	RESET(ch,false);
	scanf("%s %s",a,b);
	ll l=strlen(a);
	sort(a,a+l);
	reverse(a,a+l);
	if(strlen(a)<strlen(b))	printf("%s",a);
	else if(a[0]<b[0])		printf("%s",a);	
	else
	{
		rep(i,0,l-1)
		{
			if(foo)
			{
				rep(j,0,l-1)
				{
					if(!ch[j])
					{
						c[i] = a[j];
						ch[j] = true;
						break;
					}
				}
			}
			else
			{
				rep(j,0,l-1)
				{
					if(a[j]<=b[i] && c[i]<a[j] && !ch[j])	
					{
						if(k!=-1)
							ch[k] = false;
						c[i] = a[j];
						ch[j]=true;
						k=j;
					}
				}
				k=-1;
				if(c[i]<b[i])	foo = true;
			}
		}
		c[l] = '\0';
		printf("%s",c);
	}
	return  0;
}













//?


