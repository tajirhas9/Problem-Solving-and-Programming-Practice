#include<bits/stdc++.h> /*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */
using namespace std;
//using namespace __gnu_pbds;

//typedefs

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;;
typedef vector<pii> vii;

//#Defines
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()
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

bool b[500][500];
int r,c;
vii pos;
int dist[500][500];

void bfs() {
	queue < pii > q;

	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			dist[i][j] = inf;
			if(b[i][j]) {
				dist[i][j] = 0;
				q.push(mp(i,j));
			}
		}
	}

	while(!q.empty()) {
		pii top = q.front();
		q.pop();

		for(int i = 0; i < 4; ++i) {
			int px,py;
			px = top.F + fx[i];
			py = top.S + fy[i];
			if(px >= 0 && px < r && py >= 0 && py < c) {
				if(dist[px][py] > dist[top.F][top.S] + 1) {
					dist[px][py] = dist[top.F][top.S] + 1;
					q.push(mp(px,py));
				}
			}
		}
	}
}
bool isOk(int x) {
	dbg(x);
	vii u;
	
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			if(dist[i][j] > x)
				u.pb(mp(i,j));
		}
	}
	if(u.empty() || u.size() == 1)	return true;
	dbg(u);
	int mn = inf;
	for(auto f : u) {
		int z = 0;
		for(auto g : u) {
			if(f == g)	continue;
			int d = abs(f.F - g.F) + abs(f.S -g.S);
			z = max(z,d);
		}
		mn = min(mn,z);
	}
	dbg(mn);
	return mn <= x;
}

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();

	int T;
	
	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cin >> r >> c;

		string s;
		for(int i = 0; i < r; ++i) {
			cin >> s;
			for(int j = 0; j < c; ++j) {
				b[i][j] = (s[j] == '1');
			}
		}
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j)
				if(b[i][j])
					pos.pb(mp(i,j));
		}
		int lo = 0 , hi = r+c+1 , loop = 100;
		int ans = inf;

		bfs();

		for(int i = 0; i < r; ++i)
			dbg(dist[i],c);

		while(lo < hi && loop--) {
			int mid = (lo+hi)/2;

			if(isOk(mid)) {
				hi = mid;
				ans = mid;
			}
			else
				lo = mid+1;
//			dbg(lo,hi);
		}
		if(lo <= hi && isOk(lo))
			ans = lo;
		cout << "Case #" << kase << ": " << ans << endl;
		pos.clear();
	}
	
	return 0;
}






//?
