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
	ll i,j,k,n;
	char s[1123456];
	cin >> n;
	rep(i,0,n-1)
		cin >> s[i];
	ll cur_x,pre_x,cur_y,pre_y,div_x,div_y,tx,ty,coin=0;
	bool zone1,zone2;
	if(s[0]=='R')
	{
		cur_x = 1;
		cur_y = 0;
		div_x = div_y = 0;
		zone2 = true;
		zone1 = false;
	}
	else
	{
		cur_x = 0;
		cur_y = 1;
		div_x = div_y = 1;
		zone1 = true;
		zone2 = false;
	}
	rep(i,1,n-1)
	{
		if(s[i] =='R')
		{
			tx = cur_x;
			ty = cur_y;
			cur_x = cur_x+1;
			cur_y = cur_y;
			pre_x = tx; pre_y = ty;
			div_x  = div_y = cur_y;
			//cout << cur_x << " "<< cur_y <<endl;
			//cout << div_x << " " << div_y << endl << endl;
			if(pre_x<= div_x && cur_x > div_x && zone1)
			{
				//cout << cur_x << " " << cur_y << endl;
				coin++;
				zone1 = false; zone2 = true;
			}
		}
		else
		{
			tx = cur_x;
			ty = cur_y;
			cur_x = cur_x;
			cur_y = cur_y+1;
			pre_x = tx; pre_y = ty;
			div_x  = div_y = cur_x;
			//cout << cur_x << " "<< cur_y <<endl;
			//cout << div_x << " " << div_y << endl << endl;
			if(pre_y <= div_y && cur_y > div_y && zone2)	
			{
				//cout << cur_x << " "<< cur_y <<endl;
				coin++;
				zone2 = false;
				zone1 = true;
			}
		}
	}
	cout << coin << endl;
	return 0;
}













//?


