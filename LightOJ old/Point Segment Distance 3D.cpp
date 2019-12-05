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
//typedef string string;
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
//inline bool isLeapYear(ll y) 			{ return ((y%400==0) || (y%4==0 && y%100!=0)); }
inline void optimize(void) 				{ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
//inline bool isInside(pii p,ll n,ll m)	{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); };
//inline bool isInside(pii p,ll n)		{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); };
//inline bool isSquare(ll x) 				{ ll s = sqrt(x);	return (s*s==x); };
//inline bool isFib(ll x) 				{ return isSquare(5*x*x+4)|| isSquare(5*x*x-4); };
//inline bool isPowerOfTwo(ll x)			{ return ((1LL<<(ll)log2(x))==x); };
//ll primeMarked[MAX/64 + 2];
//inline bool on(ll x) 					{ return (primeMarked[x/64] & (1<<((x%64)/2))); };
//inline void mark(ll x)					{ primeMarked[x/64] |= (1<<((x%64)/2)); };
//inline ll bitOn(ll x,ll k)				{	return x |= 1<<k;	}
//inline ll bitOff(ll x,ll k)				{	return x ^= 1<<k;	}
//inline bool checkBit(ll x,ll k)			{	return x &= 1<<k;	}
//const ll mod = 1e9+7;
//const double pi = acos(-1.0);
const double eps = 0.000000000000001;
/*struct func
{
	//this is a sample overloading function for sorting stl
	bool operator()(pii const &a, pii const &b)	
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
struct point
{
	double x,y,z;
};
point a,b,p;
double f(point aa,point bb)
{
	double xx,yy,zz;
	xx = aa.x-bb.x;
	yy = aa.y-bb.y;
	zz = aa.z-bb.z;
	return sqrt((xx*xx+yy*yy+zz*zz));
}
double ternary_search(void)
{
	point mid1,mid2;
	int loop=0;
	double p1,p2;
	p1 = f(a,p); 	p2 = f(b,p);
	while(++loop<400)
	{
		mid1.x = (2*a.x+b.x)/3.0;
		mid1.y = (2*a.y+b.y)/3.0;
		mid1.z = (2*a.z+b.z)/3.0;
		
		mid2.x = (2*b.x+a.x)/3.0;
		mid2.y = (2*b.y+a.y)/3.0;
		mid2.z = (2*b.z+a.z)/3.0;
		
		p1 = f(mid1,p); 	p2 = f(mid2,p);
		if(p1>p2)
			a = mid1;
		else
			b = mid2;
	}
	return abs(p1+p2)/2.0;
}
int main()
{
	//optimize();
	int i,T;
	scanf("%d",&T);
	rep(i,1,T)
	{
		scanf("%lf %lf %lf",&a.x,&a.y,&a.z);
		scanf("%lf %lf %lf",&b.x,&b.y,&b.z);
		scanf("%lf %lf %lf",&p.x,&p.y,&p.z);
		printf("Case %d: %.15lf\n",i,ternary_search());
	}
	return 0;
}













//?
