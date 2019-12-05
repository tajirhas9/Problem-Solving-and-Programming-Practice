#include <bits/stdc++.h>
using namespace std;

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

//#Defines

#define pb push_back
//#define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()
#define endl '\n'
#define pf printf
#define sf scanf
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


class ArticulationPoint {
private:
	int node,edge,timer;
	vector < bool > vis;
	vector < int > tin,fup;
	set < int > art_point;
	set < pair < int , int > > art_bridge;
	vector < vector < int > > adj;

	void dfs(int u, int p = -1) {
		vis[u] = true;
		tin[u] = fup[u] = timer++;
		int children = 0;

		for(auto v : adj[u]) {
			if(v == p)	continue;
			if(vis[v]) 
				fup[u] = min(fup[u] , tin[v]);
			else {
				dfs(v,u);
				fup[u] = min(fup[u] , fup[v]);
				if(fup[v] > tin[u])  {
					art_point.insert(u);
					art_bridge.insert(make_pair(min(u,v) , max(u,v) ));
				}
				++children;
			}
		}
		if(p == -1 && children > 1)
			art_point.insert(u);
	}

	void find_cutpoints(vector < vector < int > > graph) {
		for(int i = 0; i < node; ++i) {
			if(!vis[i])
				dfs(i);
		}
	}
public:
	ArticulationPoint(vector < vector < int > > graph , int n) {
		node = n;
		adj = graph;
		timer = 0;
		vis.assign(n,false);
		tin.assign(n,-1);
		fup.assign(n,-1);

		find_cutpoints(graph);
	}

	set < int > getPoints() {
		return art_point;
	}

	set < pair < int , int > > getBridges() {
		return art_bridge;
	}
};

vvi g;
int n,m;

int main() {
	
	optimize();

	#ifdef tajir
//		freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	#else
		// online submission
	#endif

	int T;

	scanf("%d",&T);

	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d",&n);
		g.resize(n);
		for(int i = 0; i < n; ++i) {
			int u,e;
			scanf("%d (%d)",&u,&e);
			g[u].resize(e);
			for(int i = 0; i < e; ++i) {
				scanf("%d" , &g[u][i]);
			}
		}

		ArticulationPoint ap(g,n);

		set < pii > Set = ap.getBridges();

//		dbg(Set);

		printf("Case %d:\n", kase);

		printf("%d critical links\n", Set.size());

		for(auto x : Set) {
			printf("%d - %d\n", x.F , x.S);
		}

		g.clear();
	}


	return 0;
}