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
inline bool isLeapYear(ll y) 			{ return ((y%400==0) || (y%4==0 && y%100!=0)); }
inline void optimize(void) 				{ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
inline bool isInside(pii p,ll n,ll m)	{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); };
inline bool isInside(pii p,ll n)		{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); };
inline bool isSquare(ll x) 				{ ll s = sqrt(x);	return (s*s==x); };
inline bool isFib(ll x) 				{ return isSquare(5*x*x+4)|| isSquare(5*x*x-4); };
inline ll gcd(ll a,ll b)				{ return __gcd(a,b); }
inline ll lcm(ll a,ll b) 				{ return (a*(b/gcd(a,b))); }
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
	ll i,j,k,n,m,x[2000],f[2000];
	cin >> n >> m;
	RESET(x,-1);
	RESET(f,-1);
	rep(i,1,m)
	{
		cin >> j>> k;
		x[j] = k;
	}
	ll flr,rm,prd,cnt,ans1,ans2;
	bool flag = true,gotIt=false,ans=true;
	rep(prd,1,100)
	{
		rm = 1; flag = true;
		//cout << "\n\nPeriod " << prd << " :";
		rep(flr,1,100)
		{
			cnt=0;
			//cout << "\nFloor " << flr << " :\n";
			while(rm<=1000)
			{
				f[rm] = flr;
				//cout << rm << " ";
				if(x[rm] != -1 && x[rm] != f[rm]) { flag = false; break; }
				rm++;	cnt++;
				if(cnt%prd==0)	break;
			}
			if(!flag)	break;
		}
		if(flag && !gotIt)
		{
			gotIt = true;
			ans1 = f[n];
		}
		else if(flag && gotIt && ans1 != f[n])
		{
			ans = false;
			break;
		}
		else if(flag && gotIt && ans1==f[n])
		{
			ans2 = f[n];
		}
		
	}
	if(f[n]==-1 || !ans)	cout << -1 << endl;
	else 			cout << ans1 << endl;
	return  0;
}













//?

