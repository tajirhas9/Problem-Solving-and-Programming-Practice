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
inline bool isPrime(int num) { return num > 1 && (num == 2 || ((num & 1) && !on(num))); }
ll fx[] = {1,1,-1,-1};
ll fy[] = {1,-1,1,-1};*/
int halfSum;
ll dp[501][51];
ll solve(int n,int curPos,ll leftSum,ll rightSum,bool lft,int cur,int prev);
int main()
{
	optimize();
	int i,j,s,n;
	unsigned long long k=0;
	RESET(dp,0);
	cin >> n >> s;
	if(s&1)
	{
		cout << 0 << endl;
		return 0;
	}
	halfSum = s/2;
	rep(i,0,min(halfSum,9))
	{
		k += solve(n,1,i,0,true,i,-1);
	}
	cout << k << endl;
	return 0;
}
ll solve(int n,int curPos,ll leftSum,ll rightSum,bool lft,int cur,int prev)
{
	int i,p1=0,p2=0;
	if(curPos==2*n)
	{
		if(leftSum==rightSum && leftSum != 0)
			return 1;
		return 0;
	}
	if(dp[curPos][cur])	return dp[curPos][cur];
	if(curPos==n)	lft = false;
	if(lft)
	{
		rep(i,0,9)
		{
			if(leftSum+i<= halfSum)
				p1 += solve(n,curPos+1,leftSum+i,rightSum,lft,i,cur);
			else
				break;
		}
	}
	else
	{
		rep(i,0,9)
		{
			if(rightSum+i <= leftSum)
				p2 += solve(n,curPos+1,leftSum,rightSum+i,lft,i,cur);
			else
				break;
		}
	}
	return (dp[curPos][cur]=p1+p2);
}












//?

