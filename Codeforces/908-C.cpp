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
ll i,j,k,n,r;
double y[5000],cntr[5000],ans[5000];
ll s[5000];
bool x[5000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> r;
	RESET(y,0);
	RESET(x,false);
	RESET(cntr,false);
	FOR(i,0,n-1)
		cin >> s[i];
	FOR(i,0,n-1)
	{
		bool done = false;
		if(x[s[i]])
		{
			ans[i] = y[s[i]]+r;
			y[s[i]] += 2*r;
			x[s[i]] = true;
		}
		for(j=i+1,k=i-1; j<= i+r; j++,k--)
		{
			if(x[j])
			{
				ll p;
				p = 4*r*r-1;
				ans[i] = (y[s[j]]-r)+sqrt(p);
				y[s[i]] = ans[i]+r;
				x[s[i]] = true;
				done = true;
				break;
			}
			else if(x[k])
			{
				ll p;
				p = 4*r*r-1;
				ans[i] = (y[s[k]]-r)+sqrt(p);
				y[s[i]] = ans[i]+r;
				x[s[i]] = true;
				done = true;
				break;
			}
		}
		if(!done)
		{
			ans[i] = y[s[i]]+r;
			y[s[i]] += 2*r;
			x[s[i]] = true;
		}
	}
	FOR(i,0,n-1)
		cout << ans[i] << " ";
	return  0;
}













//?

