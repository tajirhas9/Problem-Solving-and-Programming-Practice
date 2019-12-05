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
ll p[2123456],front[2123456],back[2123456],ans[2123456];
int main()
{
	optimize();
	ll i,j,k,n,cus;
	map<ll,bool> m;
	priority_queue<ll,vector<ll>,greater<ll>> q1,q2,q3;
	cin >> n;
	rep(i,0,n-1)
	{
		cin >> p[i];
		m[p[i]] = false;
	}
	rep(i,0,n-1)	cin >>	front[i];
	rep(i,0,n-1)	cin >>	back[i];
	rep(i,0,n-1)
	{
		if(front[i]==1 || back[i]==1)	q1.push(p[i]);
		if(front[i]==2 || back[i]==2)	q2.push(p[i]);
		if(front[i]==3 || back[i]==3)	q3.push(p[i]);
	}
	cin >> cus;
	rep(i,1,cus)
	{
		cin >> k;
		if(k==1)
		{
			while(m[q1.top()] && !q1.empty())	q1.pop();
			if(q1.empty())	ans[i] = -1;
			else  		
			{
				ans[i] = q1.top();
				m[q1.top()] = true;
				q1.pop();
			}
		}
		else if(k==2)
		{
			while(m[q2.top()] && !q2.empty())	q2.pop();
			if(q2.empty())	ans[i] = -1;
			else 
			{
				ans[i] = q2.top();
				m[q2.top()] = true;
				q2.pop();
			}
		}
		else if(k==3)
		{
			while(m[q3.top()] && !q3.empty())	q3.pop();
			if(q3.empty())	ans[i] = -1;
			else 
			{
				ans[i] = q3.top();
				m[q3.top()] = true;
				q3.pop();
			}
		}
	}
	rep(i,1,cus)	cout << ans[i] << " ";
	return  0;
}













//?

