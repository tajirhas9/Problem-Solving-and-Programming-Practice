#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000007
#define INF 1000000007
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
typedef pair<double,double> pdd;
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
inline bool isInside(pdd p,double n,double m)	{ return (p.first>=0&&p.first<=n&&p.second>=0&&p.second<=m); };
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
ll fx[] = {1,1,-1,-1};
ll fy[] = {1,-1,1,-1};
double solve(pii pp,double len);
bool coordX[1234],coordY[1234];
double n,m;
double dp[1234][1234];
int main()
{
	optimize();
	//freopen("input.txt","r",stdin);
	ll i,j,k;
	cin >> n >> m;
	RESET(dp,0);
	RESET(coordX,false);
	RESET(coordY,false);
	cin >> k;
	rep(i,0,k-1)
	{
		ll x,y;
		cin >> x >> y;
		coordX[x] = true;
		coordY[y] = true;
	}
	printf("%0.0lf\n",solve(mp(0LL,0LL),0));
	return 0;
}
double solve(pii pp,double len)
{
	ll x,y;
	double p1,p2,p3;
	p1 = p2 = p3 = n*m*100*10+1;
	x = pp.first; y = pp.second;
	
	if(pp.first==n && pp.second==m)	return 0;
	if(dp[x][y])	return dp[x][y];
	
	
	if(isInside(mp(x+1,y),n,m))
		p1 = solve(mp(x+1,y),len+100)+100;
	if(isInside(mp(x,y+1),n,m))
		p2 = solve(mp(x,y+1),len+100)+100;
	if(coordX[x+1] && coordY[y+1] && isInside(mp(x+1,y+1),n,m))	
	{
		double xx,yy,l;
		xx = x+1; xx *= xx;
		yy = y+1; yy *= yy;
		l = 100*sqrt(2);
		//cout << x << " " << y << " ";
		p3 = solve(mp(x+1,y+1),len+l)+l;
		//cout << p3 << endl;
	}
	//cout << x << " " << y << ": " << min(p1,min(p2,p3)) << endl;
	return (dp[x][y] = min(p1,min(p2,p3)));
}












//?

