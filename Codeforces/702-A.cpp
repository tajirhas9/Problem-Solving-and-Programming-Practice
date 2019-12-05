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
	ll i,j,k,n,a[112346],m=0,x=0;
	ll b[112345];
	RESET(b,0);
	cin >> n;
	a[0] = 0;
	b[0] = 0;
	rep(i,1,n)
	{
		cin >> a[i];
		if(a[i]>a[i-1])	b[i] = b[i-1]+1;
		else 			b[i] = 1;
		m = max(m,b[i]);
	}
	cout << m << endl;
	return  0;
}













//?
