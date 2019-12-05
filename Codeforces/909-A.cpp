#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)	for(i=a;i<=b;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define RESET(a,b)	memset(a,b,sizeof(a))
#define lcm(a,b) (a*(b/gcd(a,b)))
#define all(a)
typedef long long ll;
typedef string string;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
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
ll i,j,k,x=0;
char f[100],l[100],a[100];
int main()
{
	ios_base::sync_with_stdio(0);
	scanf("%s %s",f,l);
	a[x++] = f[0];
	FOR(i,1,(strlen(f)-1))
	{
		if(f[i]<l[0])	a[x++] = f[i];
		else break;
	}
	a[x++] = l[0];
	FOR(i,1,strlen(l)-1)
	{
		if(l[i]>l[i-1])	a[x++] = l[i];
		else break;
	}
	a[x] = '\0';
	printf("%s",a);
	return  0;
}













//?

