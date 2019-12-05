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
ll i,j,k,n,t,a[123456],sum[123456],m=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>t;
	FOR(i,0,n-1)	cin >> a[i];
	sum[0] = a[0];
	FOR(i,1,n-1)
		sum[i] = a[i]+sum[i-1];
	if(sum[n-1]<=t) m = n;
	else
	{
		FOR(i,0,n-1)
		{
			ll p;
			//cout << i+1 << " ";
			p = (ll)(upper_bound(sum+i,sum+n,(t+max((ll)0,sum[i-1])))-sum-i);
			//cout << (ll)(lower_bound(sum+i,sum+n,(t+sum[i]))-sum) << " " << sum[p+i-1]-max((ll)0,sum[i-1]) << " ";
			//cout << p << endl;
			m = max(m,p);
		}
	}
	cout << m << endl;
	return  0;
}













//?
