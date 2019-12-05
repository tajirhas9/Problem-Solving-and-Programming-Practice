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
struct fount
{
	ll b,cost;
	char ch;
};
struct func
{
	//this is a sample overloading function for sorting stl
	bool operator()(fount const &a, fount const &b)	
	{
		if(a.b==b.b)
			return (a.cost<=b.cost);
		return (a.b>b.b);
	}
};
ll i,j,k,n,c,d,buyc=0,buyd=0,buy=0,bc=0,bd=0,maxB=0;
fount v[1123456];
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("../Rough/input.txt","r",stdin);
	cin >> n >> c >> d;
	FOR(i,0,n-1)
	{
		fount x;
		cin >> x.b >> x.cost >> x.ch;
		v[i] = x;
	}
	sort(v,v+n,func());
	for(i=0;i<n && buy<2;i++)
	{
		if(v[i].ch=='C' && v[i].cost<=c)
		{
			maxB += v[i].b;
			c -= v[i].cost;
			buy++;
		}
		else if(v[i].ch=='D' && v[i].cost<=d)
		{
			maxB += v[i].b;
			d -= v[i].cost;
			buy++;
		}
	}
	if(buy<2)	cout << 0 << endl;
	else 		cout << maxB << endl;
	return  0;
}













//?

