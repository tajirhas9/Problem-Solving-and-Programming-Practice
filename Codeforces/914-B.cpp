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
ll n;
vl v;
int main()
{
	optimize();
	ll i,j=0,k;
	bool ag,co;
	ag = co = false;
	cin >> n;
	rep(i,0,n-1)
	{
		ll x;
		cin >> x;
		v.pb(x);
	}
	sort(v.begin(),v.end());
	//cout << v.size() << endl;
	ag = true;
	while(1)
	{
		if(v.size()<=0)	break;
		bool ff = false;
		ll cnt=0;
		if(ag)
		{
			ag = false; co = true;
		}
		else
		{
			ag = true; co = false;
		}
		ll last = v.size()-1;
		ll choose = v[last];
		//v.erase(v.begin()+last);
		i= last-1;
		while(v[i]==choose)
		{
			ff =true;
			cnt++;
			i--;
		}
		if(ff)
		{
			if(cnt&1)
			{
				choose = *v.begin()+i;
				v.erase(v.begin()+i);
				//rep(k,0,v.size()-1)	cout << v[k] << " ";
				//cout << endl;
				i--;
				while(v[i]==choose && i>=0)	i--;
			}
		}
		else
		{
			choose = *v.begin()+last;
			v.erase(v.begin()+last);
			i = v.size()-1;
			while(v[i]==choose && i>=0)	i--;
		}
		cout << v.size() << endl;
		//rep(k,0,v.size()-1)	cout << v[k] << " ";
				//cout << endl;
		cout << *v.begin()+i << endl;
		if(i>0)	v.erase(v.begin(),v.begin()+i);
		rep(k,0,2)	cout << v[k] << " ";
		cout << endl;
	}
	if(ag)	cout << "Agasa" << endl;
	else 	cout << "Conan" << endl;
	return  0;
}













//?

