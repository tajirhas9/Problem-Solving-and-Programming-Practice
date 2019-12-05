#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)	for(i=a;i<=b;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define RESET(a,b)	memset(a,b,sizeof(a))
#define lcm(a,b) (a*(b/gcd(a,b)))
typedef long long ll;
typedef string string;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef set<ll> setl;
typedef set<string> sets;
typedef set<ll>::iterator setl_it;
typedef set<string>::iterator sets_it;
typedef vector<ll>::iterator vl_it;
typedef vector<string>::iterator vs_it;
ll i,j,k;
vii r;
map<pii,ll> cnt;
struct func
{
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
	ll n,pos,s,p;
	cin >> n >> pos;
	FOR(i,0,n-1)
	{
		cin >> s >> p;
		r.pb(mp(s,p));
		cnt[mp(s,p)]++;
	}
	sort(r.begin(),r.end(),func());
	cout << cnt[r[pos-1]] << endl;
	return  0;
}













//?

