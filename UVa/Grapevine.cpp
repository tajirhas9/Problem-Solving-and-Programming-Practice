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
vl v[505];
int n,m;
int main()
{
	optimize();
	freopen("input.txt","r",stdin);
	int i,j,k;
	while((cin >> n >> m) && n && m)
	{
		rep(i,0,n-1)
		{
			rep(j,0,m-1)
			{
				cin >> k;
				v[i].pb(k);
			}
		}
		int q,l,r;
		cin >> q;
		rep(j,0,q-1)
		{
			ll p,q;
			ll cons=0,coordX1=0,coordX2=m,curSquare=0,ansSquare=0,actX1=0,actX2=0;
			bool flag = false;
			cin >> l >> r;
			rep(i,0,n-1)
			{
				p = (int) (lower_bound(all(v[i]),l)-v[i].begin());
				q = (int) (upper_bound(all(v[i]),r)-v[i].begin());
				cons++;
				coordX1 = p;
				coordX2 = q;
				if(coordX1>= actX1)
				{
					if(coordX2>=actX2)
					{
						curSquare = (actX2-coordX1);
						actX1 = coordX1;
						curSquare = min(curSquare,cons);
					}
					else
					{
						curSquare = (coordX2-coordX1);
						actX2 = coordX2; actX1 = coordX1;
						curSquare = min(curSquare,cons);
					}
					if(curSquare>=ansSquare)	ansSquare = curSquare;
					else
						cons=0;
				}
				else
					cons=0;
			}
			if(!flag)	cout << ansSquare << endl;
		}
		cout << "-" << endl;
		rep(i,0,n-1)	v[i].clear();
	}
	return 0;
}













//?


