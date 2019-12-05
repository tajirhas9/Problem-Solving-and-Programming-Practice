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

class SuffixArray {
	string s;
	int n,alphabet,k;

	vector < int > sorted_shifts,eqc;

	vector < int > sort_cyclic_shifts() {
		vector < int > p(n) , c(n) , cnt(max(alphabet , n) , 0);

		for (int i = 0; i < n; i++)
	        cnt[s[i]]++;
	    for (int i = 1; i < alphabet; i++)
	        cnt[i] += cnt[i-1];
	    for (int i = 0; i < n; i++)
	        p[--cnt[s[i]]] = i;
	    c[p[0]] = 0;
	    int classes = 1;
	    for (int i = 1; i < n; i++) {
	        if (s[p[i]] != s[p[i-1]])
	            classes++;
	        c[p[i]] = classes - 1;
	    }
	    vector<int> pn(n), cn(n);
	    for (int h = 0; (1 << h) < n; ++h) {
	    	k = h;
	        for (int i = 0; i < n; i++) {
	            pn[i] = p[i] - (1 << h);
	            if (pn[i] < 0)
	                pn[i] += n;
	        }
	        fill(cnt.begin(), cnt.begin() + classes, 0);
	        for (int i = 0; i < n; i++)
	            cnt[c[pn[i]]]++;
	        for (int i = 1; i < classes; i++)
	            cnt[i] += cnt[i-1];
	        for (int i = n-1; i >= 0; i--)
	            p[--cnt[c[pn[i]]]] = pn[i];
	        cn[p[0]] = 0;
	        classes = 1;
	        for (int i = 1; i < n; i++) {
	            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
	            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
	            if (cur != prev)
	                ++classes;
	            cn[p[i]] = classes - 1;
	        }
	        c.swap(cn);
	    }
	    eqc = c;
/*
	    for(vi :: iterator it = eqc.begin(); it != eqc.end(); ++it) {
	    	if(*it == (n-1)) {
	    		eqc.erase(it);
	    		break;
	    	}
	    }*/
	    return p;
	}

	int compare(int i, int j) {
		int l = n;
	    pair<int, int> a = mp(eqc[i], eqc[(i+l-(1 << k))%n]);
	    pair<int, int> b = mp(eqc[j], eqc[(j+l-(1 << k))%n]);
	    return a == b ? 0 : a < b ? -1 : 1;
	}

public:
	SuffixArray(string ss) : s(ss) {
		s += '$';
		n = s.size();
		alphabet = 256;

		sorted_shifts = sort_cyclic_shifts();
		sorted_shifts.erase(sorted_shifts.begin());
	}

	vector < int > get_sorted_shifts() {
		return sorted_shifts;
	}

	vector < int > get_eqc() {
		return eqc;
	}

	bool isOK() {
		for(int i = 1; i < n-1; ++i) {
			if(compare(i,0) == -1)	{
				dbg(i);
				return false;
			}
		}
		return true;
	}

};

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();
	
	int n;
	string s,s1,s2;

	cin >> n;
	cin >> s;

	
	SuffixArray sa(s);

	vector < int > p = sa.get_sorted_shifts();

	dbg(p);

	bool flag = (p[0] == 0);

	if(p[0] != 0) {
		for(int i = 0; p[i] != 0; ++i) {
			string f = s.substr(p[i] , n-p[i]);

			size_t id = s.find(f);
			dbg(f,id);
			if(id == string::npos) {
				flag = false;
				break;
			}
		}
	}

	cout << (flag ? "YES" : "NO") << endl;

	return 0;
}
