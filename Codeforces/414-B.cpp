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
ll i,j,k,n,ans=0;
ll dp[2001][2001];
bool flag=true;
ll solve(ll indx,ll cnt);
int main()
{
	ios_base::sync_with_stdio(0);
	RESET(dp,0);
	cin >> n >> k;
	cout << solve(1,1) << endl;
	return  0;
}

ll solve(ll indx,ll cnt)
{
	if(cnt>k)
	{
		if(indx<=n)
			return 1;
		return 0;
	}
	if(dp[indx][cnt]!=0)	
	{
		return dp[indx][cnt];
	}
	ll x=0;
	flag = true;
	ll i;
	for(i=indx;i<=n;i+=indx)
	{
		x += solve(i,cnt+1);
		x %= MAX;
	}
	return dp[indx][cnt] = x;
}











//?
