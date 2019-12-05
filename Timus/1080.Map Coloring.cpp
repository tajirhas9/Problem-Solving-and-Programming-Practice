#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define MOD 1000000007
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		emplace_back(x)
//#define pb(x)		push_back(x)
#define all(c)		c.begin(),c.end()
#define F 			first
#define S 			second
#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b)	__gcd(a,b)
#define lcm(a,b) ((a*b)/gcd(a,b))
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
inline bool isPowerOfTwo(ll x)			{ return ((1LL<<(ll)log2(x))==x); };
ll primeMarked[MAX/64 + 2];
inline bool on(ll x) 					{ return (primeMarked[x/64] & (1<<((x%64)/2))); };
inline void mark(ll x)					{ primeMarked[x/64] |= (1<<((x%64)/2)); };
inline ll bitOn(ll x,ll k)				{	return x |= 1<<k;	}
inline ll bitOff(ll x,ll k)				{	return x ^= 1<<k;	}
inline bool checkBit(ll x,ll k)			{	return x &= 1<<k;	}
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
};/*
void sieve(ll n) {
    for (ll i=3; i*i<n; i+=2) {
        if (!on(i)) {
            for (ll j=i*i; j<=n; j+=i+i) {
                mark(j);
            }
        }
    }
}
inline bool isPrime(int num) { return num > 1 && (num == 2 || ((num & 1) && !on(num))); }*/
//ll fx[] = {1,1,-1,-1};
//ll fy[] = {1,-1,1,-1};
int main()
{
	optimize();
	ll i,j,k,n,x;
	char col[11234],next='0';
	vl v[1000];
	bool vis[1000];
	RESET(vis,false);
	rep(i,0,100)	col[i] = '\0';
	queue<pii> q;
	cin >> n;
	rep(i,1,n)
	{
		while(cin>>x && x!=0)
		{
			v[i].pb(x);
			v[x].pb(i);
		}
		v[i].pb(100000);
	}
	q.push(mp(1,0));
	col[1] = next; next = '1';
	while(!q.empty())
	{
		pii top;
		top = q.front(); q.pop();
		vis[top.first] = true;
		//cout <<endl << top.first << "," << top.second << "->";
		rep(i,0,v[top.first].size()-1)
		{
			int x;
			x = v[top.first][i];
			//cout << x << " ";
			if(x==100000)	continue;
			if(!vis[x])
			{
				ll cc;
				cc = ((top.second) ? 0 : 1);
				col[x] = cc+'0';
				//cout << x << " " << col[x] << endl;
				vis[x] = true;
				q.push(mp(x,cc));
			}
			else if((col[x]-'0') == top.second)
			{
				//cout << x << " " << col[x] << endl;
				cout << -1 << endl;
				return 0;
			}
		}
			(next=='1') ? next = '0' : next = '1';
	}
	rep(i,1,n)	cout << col[i];
	return 0;
}













//?


