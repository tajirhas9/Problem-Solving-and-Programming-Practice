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
		if(a.F==b.F)
			return (a.S<b.S);
		return (a.F<b.F);
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
	ll i,j=0,k,n,m,a[61234],lo,hi,lo2,hi2,mid;
	scanf("%lld",&n);
	a[0] = -1;
	rep(i,1,n)	scanf("%lld",&a[i]);
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&k);
		lo = 1; hi = n;
		//printf("Finding Low:\n");
		while(++j<400 && lo<hi)
		{
			mid = lo+((hi-lo)>>1);
			//printf("mid=%lld\n",mid);
			if(a[mid]>=k)
				hi = mid-1;
			else
				lo = mid;
			//printf("lo=%lld  hi=%lld\n",lo,hi);
		}
		lo2 = 1; hi2 = n; j=0;
		//printf("Finding High:\n");
		while(++j<400 && lo2<hi2)
		{
			mid = lo2+((hi2-lo2)>>1);
			//printf("mid=%lld\n",mid);
			if(a[mid]<=k)
				lo2 = mid+1;
			else
				hi2 = mid;
			//printf("lo=%lld  hi=%lld\n",lo2,hi2);
		}
		//printf("%lld %lld\n%lld %lld\n",lo,hi,lo2,hi2);
		if((k<=a[lo] && k<=a[hi]) || a[hi]==-1)	printf("X ");
		else
		{
			if(a[hi]<k)	printf("%lld ",a[hi]);
			else		printf("%lld ",a[lo]);
		}
		if(k>=a[lo2] && k>=a[hi2])	printf("X\n");
		else
		{
			if(a[lo2]>k)	printf("%lld\n",a[lo2]);
			else		printf("%lld\n",a[hi2]);
		}
	}
	return 0;
}













//?


