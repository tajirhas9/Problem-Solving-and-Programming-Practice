#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define PI 3.1416
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define RESET(a,b)	memset(a,b,sizeof(a))
#define lcm(a,b) (a*(b/gcd(a,b)))
#define gcd(a,b)	__gcd)(a,b)
#define cin1(a)	scanf("%lld",&a)
#define cin2(a,b)	scanf("%lld %lld",&a,&b)
#define left(p)		(p<<1)
#define right(p)		((p<<1)+1)
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
void build(ll node,ll b,ll e);
ll rmq(ll node,ll b,ll e,ll i, ll j);
ll n,a[501*501],q,st[4*501*501];
int main()
{
	ll i,j,k,t,l,r,s;
	cin1(t);
	rep(i,1,t)
	{
		RESET(st,0);
		RESET(a,0);
		cin2(n,q);
		rep(j,0,(n*n-1))	cin >> a[j];
		build(1,0,(n*n-1));
		printf("Case %lld:\n",i);
		rep(j,1,q)
		{
			ll m=-1;
			cin2(l,r);
			cin1(s);
			--l; --r; --s;
			rep(k,l,l+s)
			{
				ll x,y,p;
				x = k*n+r; y = k*n+r+s;
				p = rmq(1,0,(n*n)-1,x,y);
				if(a[p]>a[m] || m==-1)	m=p;
			}
			printf("%lld\n",a[m]);
		}
	}
	return  0;
}
void build(ll node,ll b,ll e)
{
	if(b==e)	st[node] = b;
	else
	{
		build(left(node),b,((b+e)>>1));
		build(right(node),(((b+e)>>1)+1),e);
		ll p1,p2;
		p1 = st[left(node)];
		p2 = st[right(node)];
		st[node] = ((a[p1]>=a[p2]) ? p1: p2);
	}
}
ll rmq(ll node,ll b,ll e,ll i, ll j)
{
	if(i>e || j<b)	return -1;
	if(b>=i && e<=j)	return st[node];
	ll p1,p2;
	p1 = rmq(left(node),b,((b+e)>>1),i,j);
	p2 = rmq(right(node),((b+e)>>1)+1,e,i,j);
	if(p1==-1)	return p2;
	if(p2==-1)	return p1;
	return ((a[p1]>=a[p2]) ? p1 : p2);
}











//?

