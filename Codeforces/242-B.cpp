#include <bits/stdc++.h>
using namespace std;
#define MAX 1234567899
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
	bool operator()(pii const &a, pii const &b)
	{
		if(a.first==b.first)
			return (a.second<b.second);
		return (a.first>b.first);
	}
};
ll i,j,k,mi=MAX,ma=0,n,x,y;
map<pii,ll> cnt;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> x >> y;
		if(x<mi)	mi = x;
		if(x>ma)	ma = x;
		if(y<mi)	mi = y;
		if(y>ma)	ma = y;
		cnt[mp(x,y)] = i;
	}
	map<pii,ll>::iterator it;
	for(it=cnt.begin(); it != cnt.end(); it++)
	{
		if(it->first.first==mi && it->first.second==ma)
		{
			cout << it->second << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return  0;
}













//?

