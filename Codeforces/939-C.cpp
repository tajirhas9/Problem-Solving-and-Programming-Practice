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
ll fx[] = {1,1,-1,-1};
ll fy[] = {1,-1,1,-1};
int main()
{
	optimize();
	ll i,j,k,s,f,n,a[112345],sum[212345],fIndx=0,sIndx=0;
	pii pp[212345];
	cin >> n;
	rep(i,0,n-1)	cin >> a[i];
	cin >> s >> f;
	rep(i,0,n-1)
	{
		pp[i].F = a[i];
		pp[i].S = i;
		//cout << pp[i].S <<" ";
	}
	for(i=n,j=0;j<n;i++,j++)
	{
		pp[i].F = a[j];
		pp[i].S = j;
		//cout << pp[i].S << " ";
	}
	//cout << endl;
	sum[0] = a[0];
	rep(i,1,(2*n)-1)
		sum[i] = pp[i].first+sum[i-1];
	ll dif = f-s;
	dif--;
	ll p;
	p = sum[dif];
	rep(i,1,2*n-1-dif)
	{
		ll p1;
		p1 = sum[i+dif]-sum[i-1];
		//cout << i+dif << " " << i << " " << sum[i+dif]-sum[i-1] << endl;
		if(p1>p)
		{
			fIndx = pp[i].S;
			sIndx = pp[i+dif].S;
			p = p1;
		}
	}
	//cout << fIndx << endl;
	ll tme=0,cnt=0;
	tme = fIndx+1;
	if(s>=tme)
	{
		cout << 1+(s-tme) << endl;
	}
	else
	{
		while(tme != s)
		{
			tme++;
			if(tme>n)	tme=1;
			cnt++;
		}
		cout << cnt+1 << endl;
	}
	return 0;
}













//?


