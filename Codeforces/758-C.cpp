#include <bits/stdc++.h>
using namespace std;
#define MAX 1123400000000000000
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
int main()
{
	optimize();
	ll i,j,k,n,m,x,y,a[123][123],lft,t;
	cin >> n >> m >> k >> x >> y;
	ll ma,mi=MAX,prd;
	RESET(a,0);
	t = n*m+(max((ll)0,n-2))*m;
	prd = floor(k/t);
	lft = k%t;
	//cout << lft << endl;
	while(lft>0)
	{
		for(i=0;i<n && lft>0; i++)
		{
			for(j=0;j<m && lft>0; j++,lft--)
			{
				a[i][j]++;
			}
		}
		//cout << lft << endl;
		for(i=n-2;i>0 && lft>0; i--)
		{
			for(j=0;j<m && lft>0; j++,lft--)
			{
				a[i][j]++;
			}
		}
	}
	ma = 0;
	
		for(i=0;i<n; i++)
		{
			for(j=0;j<m; j++,lft--)
			{
				if(i==0 || i==n-1)
					a[i][j] += prd;
				else
					a[i][j] += 2*prd;
				ma = max(ma,a[i][j]);
				mi = min(mi,a[i][j]);
				//cout << a[i][j] << " ";
				//cout << mi << " ";
			}
			//cout << endl;
		}
	cout << ma << " " << mi << " " << a[x-1][y-1] << endl;
	return  0;
}












//?

