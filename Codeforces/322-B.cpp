#include <bits/stdc++.h>
using namespace std;
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
ll i,j,k,n=0,a[5];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> a[0] >> a[1] >> a[2];
	ll b[5];
	rep(i,0,2)
	{
		b[0] = a[0]; b[1] = a[1]; b[2] = a[2];
		b[0] -= i; b[1] -= i; b[2] -= i;
		if(b[0]>0&&b[1]>0&&b[2]>0)
			n = max(n,(i+(b[0]/3+b[1]/3+b[2]/3)));
		else
			n = max(n,(b[0]/3+b[1]/3+b[2]/3));
	}
	cout << n << endl;		
	return  0;
}













//?
