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
ll i,j,k;
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	ll n,m,total;
	cin >> n >> m;
	total=n+m;
	if(n<m)	{ i=0; total--; }
	else 	i=1;
	for(;i<=total && (m>0 && n>0);i++)
	{
		if(i&1)	
		{
			cout << "B";
			--n;
		}
		else 	
		{
			cout << "G";
			--m;
		}
	}
	if(m<=0)
	{
		while(n>0)
		{
			cout << "B";
			n--;
		}
	}
	else
	{
		while(m>0)
		{
			cout << "G";
			m--;
		}
	}
	return  0;
}













//?

