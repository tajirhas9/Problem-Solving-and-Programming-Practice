#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define MOD 1000000007
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		emplace_back(x)
//#define pb(x)		push_back(x)
#define F 			first
#define S 			second
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
inline bool isLeapYear(ll y) { return ((y%400==0) || (y%4==0 && y%100!=0)); }
inline void optimize(void) { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
inline bool isInside(pii p,ll n,ll m)	{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); };
inline bool isInside(pii p,ll n)	{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); };
const ll mod = 1e9+7;
const double pi = acos(-1.0);
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
ll fx[] = {1,1,-1,-1};
ll fy[] = {1,-1,1,-1};
vl v[2123456];
setl s;
map<ll,ll> m;
ll color[2123456],vis[2123456],nowRoot,cnt=0;
bool flag = true;
bool dfs(ll n,ll p);
int main()
{
	optimize();
	ll i,j,k,n,change=0;
	cin >> n;
	rep(i,1,n-1)
	{
		ll x,y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	rep(i,1,n)
	{
		cin >> color[i];
		m[color[i]] = i; 
	}
	map<ll,ll>::iterator itm;
	for(itm= m.begin(); itm != m.end(); itm++)
	{
		s.insert(itm->second);
	}
	//cout << s.size() << endl;
	if(s.size()==1)	{ cout << "YES" << endl << *(s.begin()) << endl; return 0; }
	//if(s.size()>3)	{ cout << "NO" << endl; return 0; }
	setl_it it;
	for(it = s.begin(); it != s.end(); it++)rep(i,1,n)
	{
		RESET(vis,-1);
		nowRoot = *it;
		vis[*it] = 0;
		if(dfs(*it,*it))	{ cout << "YES\n" << *it << endl; return 0; }
		//cout << endl;
	}
	cout << "NO\n";
	return  0;
}
bool dfs(ll par,ll root)
{
	ll i;
	if(color[root] != color[par] && root != nowRoot)	return false;
	vis[par] = 0;
	//cout << "par = " << par << endl;
	rep(i,0,v[par].size()-1)
	{
		//cout << v[par][i] << endl;
		if(vis[v[par][i]] == -1)
		{
			//cout << "e" << v[par][i] << endl;
			if(!dfs(v[par][i],par))	return false;
		}
	}
	vis[par] = 1;
	return true;
}












//?

