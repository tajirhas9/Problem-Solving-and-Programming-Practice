#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;

#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
//#define pb push_back
#define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define endl '\n'
#define pf printf
#define sf scanf
#define left __left
#define right __right
#define tree __tree

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

int fx[] = {0, 0, +1, -1};
int fy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline bool isLeapYear(ll year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
inline bool isInside(pii p,ll n,ll m)	{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<m); }
inline bool isInside(pii p,ll n)		{ return (p.first>=0&&p.first<n&&p.second>=0&&p.second<n); }
inline bool isSquare(ll x) 				{ ll s = sqrt(x);	return (s*s==x); }
inline bool isFib(ll x) 				{ return isSquare(5*x*x+4)|| isSquare(5*x*x-4); }
inline bool isPowerOfTwo(ll x)			{ return ((1LL<<(ll)log2(x))==x); }

struct func
{
	//this is a sample overloading function for sorting stl
	bool operator()(pii const &a, pii const &b)	
	{
		if(a.F==b.F)
			return (a.S<b.S);
		return (a.F<b.F);
	}
};
/*
bool sieve[1010000];
vi prime;

void seive(int limit) {
	limit += 100;
    int sqrtn = sqrt(limit);
    for(int i = 3; i <= sqrtn; i += 2) {
		if(!seive[i>>1]) {
			for(int j = i * i; j < limit; j += i + i) {
				seive[j>>1] = 1;
			}
		}
	}
	prime.pb(2);
	for(int i = 3; i < limit; i += 2) {
		if(!seive[i>>1]) prime.pb(i);
	}
}
*/

//
//debug
#ifdef tajir
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
	os << "{";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
			os << *it;
	}
	return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
			os << *it;
	}
	return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << it -> first << " = " << it -> second ;
		}
	return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () {
	cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
	for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
	cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
	cerr << arg << ' ';
	faltu(rest...);
}
#else
#define dbg(args...)
#endif // tajir

int main()
{
	optimize();
	int T,k,i,j,a,b;
	cin >> T;
	rep(k,1,T)
	{
		cin >> a >> b;
		//cout << a << " " << b << endl;
		if(b==1)
		{
			for(i=1;i<=a;i++)
			{
				for(j=1;j<=i;j++)
					cout << "*";
				cout << endl;
			}
			for(i=a-1;i>=1;i--)
			{
				for(j=i;j>=1;j--)
					cout << "*";
				cout << endl;
			}
		}
		else if(b==2)
		{
			for(i=a;i>=1;i--)
			{
				for(j=1;j<i;j++)
					cout << " ";
				for( ; j<=a;j++)
					cout << "*";
				cout << endl;
			}
			for(i=1;i<a;i++)
			{
				for(j=1;j<=i;j++)
					cout << " ";
				for( ; j<=a;j++)
					cout << "*";
				cout << endl;
			}
		}
		else if(b==3)
		{
			int p=1;
			for(i=1;i<=a;i++)
			{
				for(j=1;j<=(a-i);j++)
					cout << " ";
				for(j=1;j<=p;j++)
					cout << "*";
				cout << endl;
				p += 2;
			}
			p -= 4;
			for(i=1;i<a;i++)
			{
				for(j=1;j<=i;j++)
					cout << " ";
				for(j=1;j<=p;j++)
					cout << "*";
				cout << endl;
				p -= 2;
			}
		}
		else
		{
			int x = a/2,dot;
			if(a&1)	x++;
			for(i=1;i<=a;i++)
			{
				dot=0;
				for(j=1;j<=x;j++,dot++)
					cout << "*";
				for(j=1;j<i;j++,dot++)
					cout << " ";
				while(++dot<(a-i))
					cout << "*";
				cout << endl;
				x--;
			}
		}
	}
	return 0;
}






//?