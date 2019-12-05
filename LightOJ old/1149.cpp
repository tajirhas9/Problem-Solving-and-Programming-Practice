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

/*
    Implementation of Hopcroft-Karp algorithm of finding maximum matching
    Running time:
        O(|E||V|^{1/2})
    Usage:
        - add edges by AddEdge()
        - indexing is 1-based
        - call Match() to generate the macimum matching
        - MinimumVertexCover() finds a vertex cover of minimum size
        - Maximum independent set is the complement of minimum vertex cover
    Input:
        - graph, constructed using AddEdge()
    Output:
        - number of matching in the maximum matching
        - right, node l of the left is matched with node right[l] of the right, (right[l] = 0 if unmatched)
        - left, node r of the right is matched with node left[r] of the left, (left[r] = 0 if unmatched)
    Todo:
        - Probably convert to 0-base indexing
    Tested Problems:
        - UVA: 12880
*/

struct HopcroftKarp {
    int n, m;
    vector <vector <int>> adj;
    vector <int> right, left;
    vector <int> dist;

    HopcroftKarp (int n, int m): n(n), m(m), adj(n + 1) {}

    void AddEdge (int l, int r) {
        adj[l].push_back(r);
    }

    bool bfs () {
        queue <int> q;
        dist = vector <int>(n + 1, -1);
        for (int l = 1; l <= n; ++l) {
            if (right[l] == 0) {
                dist[l] = 0;
                q.push(l);
            }
        }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            if (dist[0] == -1 || dist[l] < dist[0]) {
                for (auto& r : adj[l]) {
                    if (dist[left[r]] == -1) {
                        dist[left[r]] = dist[l] + 1;
                        q.push(left[r]);
                    }
                }
            }
        }
        return dist[0] != -1;
    }

    bool dfs (int l) {
        if (l != 0) {
            for (auto& r : adj[l]) {
                if (dist[left[r]] == dist[l] + 1 && dfs(left[r])) {
                    left[r] = l;
                    right[l] = r;
                    return true;
                }
            }
            dist[l] = -1;
            return false;
        }
        return true;
    }

    int Match () {
        right = vector <int>(n + 1, 0);
        left = vector <int>(m + 1, 0);
        int ret = 0;
        while (bfs()) {
            for (int l = 1; l <= n; ++l) {
                if (right[l] == 0 && dfs(l)) {
                    ret++;
                }
            }
        }
        return ret;
    }

    /*
        Finds minimum vertex cover
        Running time:
            O(|V|+|E|)
        Output:
            - leftCover, leftCover[l] is true iff node l of the left side is in the minimum vertex cover
            (not in the maximum independent set)
            - leftCover, rightCover[r] is true iff node r of the right side is in the minimum vertex cover
            (not in the maximum independent set)
    */

    void MinimumVertexCover (vector <bool>& leftCover, vector <bool>& rightCover) {
        leftCover = vector <bool>(n + 1, true), rightCover = vector <bool>(m + 1, false);
        queue <int> q;
        dist = vector <int>(n + 1, -1);
        for (int l = 1; l <= n; ++l) {
            if (right[l] == 0) {
                dist[l] = 0;
                q.push(l);
            }
        }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            leftCover[l] = false;
            if (dist[0] == -1 || dist[l] < dist[0]) {
                for (auto& r : adj[l]) {
                    if (dist[left[r]] == -1) {
                        dist[left[r]] = dist[l] + 1;
                        rightCover[r] = true;
                        q.push(left[r]);
                    }
                }
            }
        }
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
	
	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int n,m;
		int a[101] , b[101];
		HopcroftKarp bipart(100,10000);
		cin >> n;
		for(int i = 1; i <= n; ++i)
			cin >> a[i];
		cin >> m;
		for(int i = 1; i <= m ; ++i)
			cin >> b[i];
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(b[j] % a[i] == 0) 
					bipart.AddEdge(i,j);
			}
		}
		cout << "Case " << kase << ": " <<  bipart.Match() << endl;
	}
	
	return 0;
}






//?
