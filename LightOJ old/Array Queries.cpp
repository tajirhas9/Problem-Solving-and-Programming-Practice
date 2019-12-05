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
#define left(p)	(p<<1)
#define right(p)	((p<<1)+1)
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
void build(ll node,ll b,ll e);
ll rmq(ll node,ll b,ll e,ll i,ll j);
ll n,q,a[123456],st[4*123456];
int main()
{
	ios_base::sync_with_stdio(0);
	ll t,i,j,k,l,r;
	scanf("%lld",&t);
	rep(i,1,t)
	{
		scanf("%lld %lld",&n,&q);
		rep(j,0,n-1)	scanf("%lld",&a[j]);
		build(1,0,n-1);
		printf("Case %lld:\n",i);
		rep(j,1,q)
		{
			scanf("%lld %lld",&l,&r);
			ll p;
			p = rmq(1,0,n-1,l-1,r-1);
			printf("%lld\n",a[p]);
		}
	}
	return  0;
}
void build(ll node,ll b,ll e)
{
	if(b==e)	st[node] = b;
	else
	{
		build(left(node),b,((b+e)/2));
		build(right(node),((b+e)/2)+1,e);
		ll p1,p2;
		p1 = st[left(node)];
		p2 = st[right(node)];
		st[node] = ((a[p1]<=a[p2])	? p1: p2);
	}
	return;
}
ll rmq(ll node,ll b,ll e,ll i,ll j)
{
	if(i>e || j<b)	return -1;
	if(b>=i && e<=j)
		return st[node];
	ll p1,p2;
	p1 = rmq(left(node),b,((b+e)/2),i,j);
	p2 = rmq(right(node),((b+e)/2)+1,e,i,j);
	if(p1==-1)	return p2;
	if(p2==-1)	return p1;
	return ((a[p1]<=a[p2]) ? p1 : p2);
}











//?

