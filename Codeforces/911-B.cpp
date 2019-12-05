#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)	for(i=a;i<=b;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define RESET(a,b)	memset(a,b,sizeof(a))
#define lcm(a,b) (a*(b/gcd(a,b)))
#define all(a)
#define MAX 123456
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
ll i,j,k,n,a,b,x,y,c,d;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> a >> b;
	if(n==a+b)	{ cout << 1 << endl;	return 0; }
	x = 0;
	for(i=1,j=n-1;i<n; i++, j--)
	{
		c = a/i; d = b/j;
		y = min(c,d);
		x = max(x,y);
	}
	cout << x << endl;
	return  0;
}













//?

