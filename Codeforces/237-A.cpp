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
ll i,j,k,n,cnt=0,av=0;
pii a[112345],tme;
ll c[112345];
int main()
{
	ios_base::sync_with_stdio(0);
	RESET(c,0);
	cin >> n;
	rep(i,0,n-1)
		cin >> a[i].first >> a[i].second;
	c[0] = 1;
	rep(i,1,n-1)
	{
		if(a[i]==a[i-1])	c[i] = c[i-1]+1;
		else
			c[i] = 1;
	}
	cout << *max_element(c,c+n) << endl;
	return  0;
}













//?

