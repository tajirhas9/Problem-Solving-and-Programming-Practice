#include <bits/stdc++.h>
using namespace std;
//#define MAX 1000000007
//#define MOD 1000000007
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
//typedef string string;
typedef pair<double,double> pdd;
/*typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setl;
typedef set<string> sets;
typedef set<ll>::iterator setl_it;
typedef set<string>::iterator sets_it;
typedef vector<ll>::iterator vl_it;
typedef vector<string>::iterator vs_it;
inline bool isLeapYear(ll y) 			{ return ((y%400==0) || (y%4==0 && y%100!=0)); }*/
inline void optimize(void) 				{ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }/*
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
const double pi = acos(-1.0);*/
const double eps = 0.00000001;
/*struct func
{
	//this is a sample overloading function for sorting stl
	bool operator()(pdd const &a, pdd const &b)	
	{
		if(a.F==b.F)
			return (a.S<b.S);
		return (a.F<b.F);
	}
};
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
pdd a,b,c,d;
double f(pdd x,pdd y);
double ternary_search(void)
{
	pdd midX1,midX2,midY1,midY2;
	double p1,p2;
	p1 = f(a,c); 	p2 = f(b,d);
	while(abs(p1-p2)> eps)
		{
			midX1.F = (2*a.F+b.F)/3.0;
			midX1.S = (2*a.S+b.S)/3.0;
			midX2.F = (2*b.F+a.F)/3.0;
			midX2.S = (2*b.S+a.S)/3.0;
			
			midY1.F = (2*c.F+d.F)/3.0;
			midY1.S = (2*c.S+d.S)/3.0;
			midY2.F = (2*d.F+c.F)/3.0;
			midY2.S = (2*d.S+c.S)/3.0;
			p1 = f(midX1,midY1); 	p2 = f(midX2,midY2);
			if(p2<p1)
			{
				a = midX1;
				c = midY1;
			}
			else
			{
				b = midX2;
				d = midY2;
			}
		}
		return abs(p1+p2)/2.0;
}
int main()
{
	//optimize();
	int i,T;
	scanf(" %d",&T);
	for(i=1;i<=T;i++)
	{
		scanf(" %lf %lf",&a.F,&a.S);
		scanf(" %lf %lf",&b.F,&b.S);
		scanf(" %lf %lf",&c.F,&c.S);
		scanf(" %lf %lf",&d.F,&d.S);
		
		printf("Case %d: %lf\n",i,ternary_search());
	}
	return 0;
}
double f(pdd x,pdd y)
{
	double xx,yy;
	xx = x.F-y.F;
	yy = x.S-y.S;
	return (sqrt((xx*xx+yy*yy)));
}












//?


