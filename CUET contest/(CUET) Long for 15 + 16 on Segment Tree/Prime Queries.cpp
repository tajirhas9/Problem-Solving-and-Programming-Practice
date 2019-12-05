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


#define M 1000000007
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
#define MAX 112345
#define lc (node<<1)
#define rc (lc+1)

ll st[4*MAX+10], lazy[4*MAX+10];
ll a[112345],n,q;
void update_node(ll node, ll val,ll left,ll right) {
	ll temp = val;
	if(val > 10000000) {
		for(int i = 0; prime[i] * prime[i] <= temp; ++i) {
			if(temp % prime[i] == 0) {
				while(temp % prime[i] == 0)
					temp /= prime[i];
			}
			if(temp <= 10000000)	break;
		}
	}
	st[node] = (right-left+1) * (isPrime(temp) ? 1:0) ;
	lazy[node] = val;
}

void push(ll node, ll left, ll right) {
	if(lazy[node] != 0) {
		ll tm = (left+right)>>1;
		update_node(lc, lazy[node],left,tm);
		update_node(rc, lazy[node], tm+1, right);
		lazy[node] = 0;
	}
}

void build(ll node,ll left, ll right) {
	if(left==right) {
		ll temp = a[left];
		if(a[left] > 10000000) {
			for(int i = 0; prime[i] * prime[i] <= temp; ++i) {
				if(temp % prime[i] == 0) {
					while(temp % prime[i] == 0)
						temp /= prime[i];
				}
				if(temp <= 10000000)	break;
			}
		}
		st[node] = ((isPrime(temp) ? 1:0 ));
		return;
	}
	ll tm = (left+right)>>1;
	build(lc, left,tm);
	build(rc, tm+1, right);
	st[node] = st[lc] + st[rc];
}

void update2(ll node, ll left, ll right, ll l, ll r, ll val) {
	if(l<= left && r >= right) {
		update_node(node,val,left,right);
		return;
	}
	push(node,left,right);

	ll tm = (left+right)>>1;

	if(r<=tm)	update2(lc, left, tm, l , r,val);
	else if(l> tm)	update2(rc, tm+1, right, l, r,val);
	else {
		update2(lc,left,tm,l,r,val);
		update2(rc,tm+1,right,l,r,val);
	}
	st[node] = st[lc] + st[rc];
}

void update1(ll node, ll left, ll right, ll pos, ll val) {
	if(left == right) {
		ll temp = a[left];
		if(a[left] > 10000000) {
			for(int i = 0; prime[i] * prime[i] <= temp; ++i) {
				if(temp % prime[i] == 0) {
					while(temp % prime[i] == 0)
						temp /= prime[i];
				}
				if(temp <= 10000000)	break;
			}
		}
		st[node] = ((isPrime(temp) ? 1:0 ));
		return;
	}
	push(node,left,right);
	ll tm = (left+right)>>1;
	if(pos <= tm)	update1(lc,left,tm,pos,val);
	else			update1(rc,tm+1,right,pos,val);
	st[node] = st[lc] + st[rc];
}

ll query(ll node, ll left, ll right, ll l, ll r) {
	if(l <= left && r >= right)
		return st[node];
	push(node,left,right);

	ll tm = (left+right)>>1;

	if(r<= tm)	return query(lc, left, tm, l, r);
	else if(l > tm)	return query(rc, tm+1, right, l, r);
	else
		return ( query(lc, left, tm, l , r) + query(rc, tm+1, right, l, r) );
}

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();
	sieve(10000005);
	scanf("%lld %lld",&n,&q);
	for(int i = 0; i < n; ++i)
		scanf("%lld",&a[i]);
	build(1,0,n-1);
//	dbg(st,10);
	while(q--) {
		char c;
		ll l,r,v;
		scanf(" %c",&c);
		if(c=='A') {
			scanf("%lld %lld",&v,&l);
			a[l-1] += v;
			update1(1,0,n-1,l-1,v);
//			dbg(st,10);
		}
		else if(c == 'R') {
			scanf("%lld %lld %lld",&v,&l,&r);
			update2(1,0,n-1,l-1,r-1,v);
//			dbg(st,10);
		}
		else {
			scanf("%lld %lld",&l,&r);
			printf("%lld\n",query(1,0,n-1,l-1,r-1) );
//			dbg(st,10);
		}
	}
	return 0;
}






//?
