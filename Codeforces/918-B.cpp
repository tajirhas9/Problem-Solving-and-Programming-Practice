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
map<ll,string> m1,m2;
string name1[212345];
string name2[212345];
int main()
{
	optimize();
	ll i,j,k,n,m;
	cin >> n >> m;
	rep(i,0,n-1)
	{
		string s1,s2;
		cin >> s1 >> s2;
		s2.append(";");
		m1[i] = s2;
		name1[i] = s1;
	}
	rep(i,0,m-1)
	{
		string s1,s2;
		cin >> s1 >> s2;
		m2[i] = s2;
		name2[i] = s1;
	}
	map<ll,string>::iterator it1;
	map<ll,string>::iterator it2;
	i=0;
	for(it2 = m2.begin(); it2 != m2.end(); it2++)
	{
		j=0;
		for(it1 = m1.begin(); it1 != m1.end(); it1++)
		{
			if(!(it2->second.compare(it1->second)))
			{
				cout << name2[i] << " " << it2->second << " #" << name1[j] << endl;
				break;
			}
			j++;
		}
		i++;
	}
	return  0;
}













//?
