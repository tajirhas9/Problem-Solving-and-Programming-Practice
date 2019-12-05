#include<bits/stdc++.h> /*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */
using namespace std;
//using namespace __gnu_pbds;

//typedefs

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
typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

/*
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;
*/

//#Defines
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
//#define pb push_back
#define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()
#define endl '\n'
#define pf printf
#define sf scanf
//#define left __left
//#define right __right
//#define tree __tree
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;


//Bit Operations
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

int fx[] = {0, 0, +1, -1};
int fy[] = {+1, -1, 0, 0};
//int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
//int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};


//Inline functions

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

//Prime Number Generator

/*
#define M 100000000
int marked[M/64 + 2];

#define on(x) (marked[x/64] & (1<<((x%64)/2)))
#define mark(x)  marked[x/64] |= (1<<((x%64)/2))

vl prime;

bool isPrime(int num) {
  return num > 1 && (num == 2 || ((num & 1) && !on(num))); 
}

void sieve(ll n) {
	for (ll i = 3; i * i < n; i += 2) {
		if (!on(i)) {
			for (ll j = i * i; j <= n; j += i + i) {
				mark(j);
			}
		}
	}
	prime.pb(2);
	for(ll i = 3; i <= n; i += 2) {
		if(!on(i))	prime.pb(i);	
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

double dist(pii x , pii y) {
	return ((x.F - y.F) * (x.F - y.F)) + ((x.S - y.S) * (x.S - y.S)) ;
}

bool check(pii p1 , pii p2 , pii intersect) {
	double dist1 = (p1.F - intersect.F) * (p1.F - intersect.F) + (p1.S - intersect.S) * (p1.S - intersect.S);
	double dist2 = (p2.F - intersect.F) * (p2.F - intersect.F) + (p2.S - intersect.S) * (p2.S - intersect.S);
	double dist3 = (p1.F - p2.F) * (p1.F - p2.F) + (p1.S - p2.S) * (p1.S - p2.S);
	return ( (sqrt(dist3) - (sqrt(dist1) + sqrt(dist2))) < eps );
}

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();
	pii a[4] , b[4];

	for(int i = 0; i < 4; ++i) {
		int x,y;
		cin >> x >> y;
		a[i] = mp(x,y);
	}
	for(int i = 0; i < 4; ++i) {
		int x,y;
		cin >> x >> y;
		b[i] = mp(x,y);
	}

	int eqA[4][3] , eqB[4][3];

	for(int i = 0; i < 4; ++i) {
		eqA[i][0] = a[i%4].S - a[(i+1)%4].S;
		eqA[i][1] = a[i%4].F - a[(i+1)%4].F;
		eqA[i][2] = - a[i%4].F * a[(i+1)%4].S + a[i%4].S * a[(i+1)%4].F;
		dbg(eqA[i][0] , eqA[i][1] , eqA[i][2]);
	}
	for(int i = 0; i < 4; ++i) {
		eqB[i][0] = b[i%4].S - b[(i+1)%4].S;
		eqB[i][1] = b[i%4].F - b[(i+1)%4].F;
		eqB[i][2] = - b[i%4].F * b[(i+1)%4].S + b[i%4].S * b[(i+1)%4].F;
	}

	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			int it1 = i , it2 = i-1;
			if(it2 < 0)	it2 = 3;
			double det;
			det = eqB[it1][0] * eqA[j][1]*1.0 - eqA[j][0] * eqB[it1][1]*1.0;
			double forx , fory;
			forx = eqB[it1][2] * eqA[j][1] * 1.0 - eqA[j][2] * eqB[it1][1] * 1.0;
			fory = eqB[it1][0] * eqA[j][2] * 1.0 - eqA[j][0] * eqB[it1][2] * 1.0;

			double x1,x2,y1,y2;
			x1 = forx / det;
			y1 = fory / det;

			if(!check(b[i%4] , b[(i+1)%4] , mp(x1,y1)))	continue;

			det = eqB[it2][0] * eqA[j][1]*1.0 - eqA[j][0] * eqB[it2][1]*1.0;
			forx = eqB[it2][2] * eqA[j][1] * 1.0 - eqA[j][2] * eqB[it2][1] * 1.0;
			fory = eqB[it2][0] * eqA[j][2] * 1.0 - eqA[j][0] * eqB[it2][2] * 1.0;

			x2 = forx / det;
			y2 = fory / det*1.0;
			if( !check(b[i] , b[it2] , mp(x2,y2)) )	continue;
			if( dist( mp(x1,y1) , mp(x2,y2) ) == dist( mp(x1,y1) , b[i] ) + dist(mp(x2,y2) , b[i]) ) {
				cout << "YES" << endl;
				
				dbg(b[it1],b[it2],a[j] , fory,det);

				return 0;
			}
		}
	}

	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			int it1 = i , it2 = i-1;
			if(it2 < 0)	it2 = 3;
			double det;
			det = eqA[it1][0] * eqB[j][1]*1.0 - eqB[j][0] * eqA[it1][1]*1.0;
			double forx , fory;
			forx = eqA[it1][2] * eqB[j][1] * 1.0 - eqB[j][2] * eqA[it1][1] * 1.0;
			fory = eqA[it1][0] * eqB[j][2] * 1.0 - eqB[j][0] * eqA[it1][2] * 1.0;

			double x1,x2,y1,y2;
			x1 = forx / det;
			y1 = fory / det;

			det = eqA[it2][0] * eqB[j][1]*1.0 - eqB[j][0] * eqA[it2][1]*1.0;
			forx = eqA[it2][2] * eqB[j][1] * 1.0 - eqB[j][2] * eqA[it2][1] * 1.0;
			fory = eqA[it2][0] * eqB[j][2] * 1.0 - eqB[j][0] * eqA[it2][2] * 1.0;

			x2 = forx / det;
			y2 = fory / det;
			
			if( dist( mp(x1,y1) , mp(x2,y2) ) == dist( mp(x1,y1) , a[i] ) + dist(mp(x2,y2) , a[i]) ) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			if(a[i] == b[j]) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}


	return 0;
}






//?
