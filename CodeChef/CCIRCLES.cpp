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

ll n;
double x[1123] , y[1123];
double rad[1123];
ll val[1123456];

pdd solve(double a, double b , double c) {
	double x1,x2,det;

	det = b*b - 4*a*c;

	x1 = -b+sqrt(det);
	x1 /= 2*a;

	x2 = -b-sqrt(det);
	x2 /= 2*a;

	return mp(x1,x2);
}

pdd intersect(double h,double k, double r, double H,double K, double HK) {
	double a,b,c;
	
	a = H*H + K*K;
	
	b = 2*K*HK;
	
	b -= 2*H*H*h;

	b -= 2*H*K*k;

	c = H*H * ( h*h + k*k - r*r );

	c -= 2*H*k*HK;

	return solve(a,b,c);
}

double Y(double x,double H,double K, double HK) {
	double nom,denom;

	nom = K*x + HK;
	denom = H;

	return nom/denom;
}

double dist(double x1, double y1 , double x2 , double y2) {

	double dist;
	dist = (x1 - x2) * (x1 - x2);
	dist += (y1 - y2) * (y1 - y2);
	return dist;
}

void get(int i, int j) {
	double H,K,HK;
	double h1,k1,h2,k2,r1,r2;

	h1 = x[i] , k1 = y[i];
	h2 = x[j] , k2 = y[j];
	r1 = rad[i] , r2 = rad[j];

	H = h1 - h2;
	K = k1 - k2;

	HK = h1*k2 - h2*k1;
	
	pdd p,q;
	double x1[2] , y1[2] , x2[2] , y2[2];

	if(H != 0) {
		p = intersect(h1,k1,r1,H,K,HK);
		q = intersect(h2,k2,r2,H,K,HK);

		x1[0] = p.F;
		y1[0] = Y(x1[0] , H,K,HK);

		x1[1] = p.S;
		y1[1] = Y(x1[1] , H,K,HK);

		x2[0] = q.F;
		y2[0] = Y(x2[0] , H,K,HK);

		x2[1] = q.S;
		y2[1] = Y(x2[1] , H,K,HK);
	}
	else {
		x1[0] = x2[0] = x1[1] = x2[1] = 0;
		p = solve(1 , -2*k1 , h1*h1 + k1*k1 - r1*r1);
		q = solve(1 , -2*k2 , h2*h2 + k2*k2 - r2*r2);

		y1[0] = p.F , y1[1] = p.S;

		y2[0] = q.F , y2[1] = q.S;
	}
	
	dbg(x1[0] , y1[0]);
	dbg(x2[0] , y2[0]);
	if( (dist(x1[1] , y1[1] , h2,k2) - dist(x1[0] , y1[0] , h2,k2) ) >= eps ) {
		if((dist(x2[1] , y2[1] , h1,k1) - dist(x2[0] , y2[0] , h1,k1) ) >= eps) {
			double dist1 = dist(x1[0] , y1[0] , x2[0] , y2[0] );
			dist1 = sqrt(dist1);

			ll distt = (ll)ceil(dist1);
			if(distt <= 1000002)
				val[distt]++;

			dist1 = dist(x1[1] , y1[1] , x2[1] , y2[1] );
			dist1 = sqrt(dist1);

			distt = (ll)floor(dist1);
			if(distt <= 1000002)
				val[distt]--;
		}
		else {
			double dist1 = dist(x1[0] , y1[0] , x2[1] , y2[1] );
			dist1 = sqrt(dist1);

			ll distt = (ll)ceil(dist1);
			if(distt <= 1000002)
				val[distt]++;

			dist1 = dist(x1[1] , y1[1] , x2[0] , y2[0] );
			dist1 = sqrt(dist1);

			distt = (ll)floor(dist1);
			if(distt <= 1000002)
				val[distt]--;
		}
	}
	else {
		if((dist(x2[1] , y2[1] , h1,k1) - dist(x2[0] , y2[0] , h1,k1) ) >= eps) {
			double dist1 = dist(x1[1] , y1[1] , x2[0] , y2[0] );
			dist1 = sqrt(dist1);

			ll distt = (ll)ceil(dist1);
			if(distt <= 1000002)
				val[distt]++;

			dist1 = dist(x1[0] , y1[0] , x2[1] , y2[1] );
			dist1 = sqrt(dist1);

			distt = (ll)floor(dist1);
			if(distt <= 1000002)
				val[distt]--;
		}
		else {
			double dist1 = dist(x1[1] , y1[1] , x2[1] , y2[1] );
			dist1 = sqrt(dist1);

			ll distt = (ll)ceil(dist1);
			if(distt <= 1000002)
				val[distt]++;

			dist1 = dist(x1[0] , y1[0] , x2[0] , y2[0] );
			dist1 = sqrt(dist1);

			distt = (ll)floor(dist1);
			if(distt <= 1000002)
				val[distt]--;
		}
	}
}

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();
		
	ll q,mx=-1,k;

	cin >> n >> q;

	for(ll i = 0; i < n; ++i)
		cin >> x[i] >> y[i] >> rad[i];

	for(ll i = 0; i < n; ++i) {
		for(ll j = i+1; j < n; ++j)
			get(i,j);
	}

	for(ll i = 1; i <= 1000000; ++i)
		val[i] += val[i-1];

	dbg(val , 20);

	while(q--) {
		cin >> k;
		cout << val[k] << endl;
	}

	
	return 0;
}






//?
