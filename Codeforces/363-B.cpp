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
ll i,j,k,n,a[11234567],sum[11234567],m=10000,pos;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	rep(i,0,n-1)	cin >> a[i];
	sum[0] = a[0];
	rep(i,1,n-1)	sum[i] = sum[i-1]+a[i];
	m = sum[0+k-1];
	pos = 0;
	for(i=1,j=i+k-1;j<n;i++,j++)
	{
		if((sum[j]-sum[i-1])<m)
		{
			pos = i;
			m = sum[j]-sum[i-1];
		}
	}
	cout << pos+1;
	return  0;
}













//?
