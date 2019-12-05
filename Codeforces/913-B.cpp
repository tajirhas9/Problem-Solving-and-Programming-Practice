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
int main()
{
	ios_base::sync_with_stdio(0);
	ll i,j,k;
	ll par[12235],n,cPar[12335];
	bool root=false,flag=false;
	RESET(par,0);
	RESET(cPar,0);
	cin >> n;
	rep(i,1,n)
	{
		ll x;
		cin >> x;
		par[i+1] = x;
	}
	rep(i,1,n)
		cPar[par[i]]++;
	rep(i,1,n)
	{
		if(cPar[i]==0 && !root)	root=true;
		else if(cPar[i]==3)	continue;
		else if(root && cPar[i] != 3) flag=true;
	}
	(flag) ?	cout << "No" << endl : cout << " Yes" << endl;
	return  0;
}













//?

