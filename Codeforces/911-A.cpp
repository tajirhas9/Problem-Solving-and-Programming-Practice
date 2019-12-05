#include <bits/stdc++.h>
using namespace std;
#define MAX 1234567891
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
		if(a.first==b.first)	return (a.second<b.second);
		return (a.first<b.first);
	}
};
ll i,j,k,n,mi=MAX;
pii a[1234567];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	FOR(i,0,n-1)
	{
		ll x;
		cin >> x;
		a[i] = mp(x,i);
	}
	sort(a,a+n,func());
	ll x,ind;
	x = a[0].first;
	ind = a[1].second-a[0].second;
	ind = abs(ind);
	FOR(i,2,n-1)
	{
		if(x!=a[i].first)	break;
		ind = min(ind,abs(a[i].second-a[i-1].second));
	}
	cout << ind << endl;
	return  0;
}













//?
