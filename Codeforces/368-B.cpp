#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)	for(i=a;i<=b;i++)
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
void build(void);
ll i,j,k,n,m,q,a[1123456],b[1123456];
bool c[1123456];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	FOR(i,1,n)	cin >> a[i];
	build();
	FOR(i,1,m)
	{
		cin >> q;
		cout << b[q] << endl;
	}
	return  0;
}

void build(void)
{
	ll prev=-1;
	RESET(c,false);
	RESET(b,0);
	for(i=n;i>0;i--)
	{
		if(c[a[i]])
		{
			b[i] = b[i+1];
		}
		else
		{
			b[i] = b[i+1]+1;
			c[a[i]] = true;
		}
	}
}










//?

