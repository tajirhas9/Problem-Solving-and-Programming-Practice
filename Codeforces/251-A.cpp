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
ll nCr(ll n,ll r)
{
	return (n*(n-1))/2;
}
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
ll i,j,k,n,a[1234567],sum=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	FOR(i,0,n-1)
		cin >> a[i];
	sort(a,a+n);
	for(i=0;i<(n-2);i++)
	{
		ll index;
		index = (ll)(upper_bound(a+i,a+n,a[i]+k)-a);
		//cout << index << " ";
		index -= (i+1);
		//cout << index << endl;
		if(index>=2)
			sum += nCr(index,2);
	}
	cout << sum << endl;
	return  0;
}













//?

