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


ll ans = inf;
ll n,a[4], b[4] , x[4] , y[4] , dataX[4][4] , dataY[4][4];

bool is_a_square(int p,int q, int r , int s) {
//	dbg(p,q,r,s);
	ll sides[6] , _X , _Y;
	int c,d;
	map < ll , ll > m;
	m[0] = p , m[1] = q , m[2] = r , m[3] = s;
	ll val = -1;
	for(int i = 0; i < 4; ++i) {
		c = i%4;
		d = (i+1)%4;
		_X = (dataX[c][m[c]] - dataX[d][m[d]]);
		_Y = ( dataY[c][m[c]] - dataY[d][m[d]] );
		_X *= _X;
		_Y *= _Y;
		sides[i] = _X + _Y;
		if(sides[i] == 0)	return false;
	}
	
	c = 0;
	d = 2;
	_X = (dataX[c][m[c]] - dataX[d][m[d]]);
	_Y = ( dataY[c][m[c]] - dataY[d][m[d]] );
	_X *= _X;
	_Y *= _Y;
	sides[4] = _X + _Y;
	if(sides[4] == 0)	return false;

	c = 1;
	d = 3;
	_X = (dataX[c][m[c]] - dataX[d][m[d]]);
	_Y = ( dataY[c][m[c]] - dataY[d][m[d]] );
	_X *= _X;
	_Y *= _Y;
	sides[5] = _X + _Y;
	if(sides[5] == 0)	return false;
	
	bool check = false;
	for(int i = 0; i <= 2; ++i) {
		int cnt = 1;
		for(int j = 0; j < 6; ++j) {
			if(i == j)	continue;
			if(sides[i] == sides[j])	cnt++;
		}
		if(cnt == 4)	{
			check = true;
			break;
		}
	}
	if(!check)	return false;

	ll aa,bb,cc;

	//sides are already squared

	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < 6; ++j) {
			if(i == j)	continue;
			for(int k = 0; k < 6; ++k) {
				if(i == k || j == k)	continue;
				ll aa = sides[i] , bb = sides[j] , cc = sides[k];
				if(aa + bb == cc || aa + cc == bb || bb + cc == aa )	return true;
			}
		}
	}
	return false;
}

void solve(int p,int q, int r, int s) {

	if(p == -1){
		for(int i = 0; i < 4; ++i)
			solve(i,q,r,s);
	}
	else if(q == -1) {
		for(int i = 0; i < 4; ++i) {
		//	if(i == p)	continue;
			solve(p,i,r,s);
		}
	}
	else if(r == -1) {
		for(int i = 0; i < 4; ++i) {
		//	if(i == p || i == q)	continue;
			solve(p,q,i,s);
		}
	}
	else if(s == -1) {
		for(int i = 0; i < 4; ++i) {
		//	if(i == p || i == q || i == r)	continue;
			solve(p,q,r,i);
		}
	}
	else {
		if(is_a_square(p,q,r,s)) 
			ans = min(ans , (ll)(p + q + r + s) );
		return;
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
	
	cin >> n;

	for(int task = 0; task < n; ++task) {
		ans = inf;
		for(int i = 0; i < 4; ++i) {
			cin >> x[i] >> y[i] >> a[i] >> b[i];
			dataX[i][0] = x[i] , dataY[i][0] = y[i];
		}

		for(int i = 0; i < 4; ++i) {
			for(int j = 1; j < 4; ++j) {
				ll x1,x2,y1,y2;
				x1 = dataX[i][j-1] , y1 = dataY[i][j-1];
				x2 = y1-b[i];
				y2 = x1-a[i];
				x2 = -x2;
		//		trim(x2,y2,x1,y1);
				x2 += a[i];
				y2 += b[i];
				dataX[i][j] = x2 , dataY[i][j] = y2;
		//		dbg(i,j,dataX[i][j] , dataY[i][j] , x1,y1);
			}
		//	dbg("\n");
		}
		solve(-1,-1,-1,-1);

		if(ans == inf)	cout << -1 << endl;
		else	cout << ans << endl;
	}
	
	return 0;
}






//?
