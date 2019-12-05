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
    Implementation of highest-label push-relabel maximum flow
    with gap relabeling heuristic.
    Running time:
        O(|V|^2|E|^{1/2})
    Usage:
        - add edges by AddEdge()
        - GetMaxFlow(s, t) returns the maximum flow from s to t
        - PreflowToFlow(s, t) converts a preflow network to a flow network
        - GetMinCut returns minimal cuts from source and sink
    Input:
        - graph, constructed using AddEdge()
        - (s, t), (source, sink)
    Output:
        - maximum flow value
    Tested Problems:
*/

template <class T> struct Edge {
    int from, to, index;
    T cap, flow;

    Edge(int from, int to, T cap, T flow, int index): from(from), to(to), cap(cap), flow(flow), index(index) {}
};

template <class T> struct PushRelabel {
    int n;
    vector <vector <Edge <T>>> adj;
    vector <T> excess;
    vector <int> dist, count;
    vector <bool> active;
    vector <vector <int>> B;
    int b;
    queue <int> Q;

    PushRelabel (int n): n(n), adj(n) {}

    void AddEdge (int from, int to, T cap) {
        if (from != to) {
            adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
            adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));
        }
    }

    void Enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < n) {
            active[v] = true;
            B[dist[v]].push_back(v);
            b = max(b, dist[v]);
        }
    }

    void Push (Edge <T>& e) {
        T amt = min(excess[e.from], e.cap - e.flow);
        if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
            e.flow += amt;
            adj[e.to][e.index].flow -= amt;
            excess[e.to] += amt;
            excess[e.from] -= amt;
            Enqueue(e.to);
        }
    }

    void Gap (int k) {
        for (int v = 0; v < n; v++) if (dist[v] >= k) {
                count[dist[v]]--;
                dist[v] = max(dist[v], n);
                count[dist[v]]++;
                Enqueue(v);
            }
    }

    void Relabel (int v) {
        count[dist[v]]--;
        dist[v] = n;
        for (auto& e : adj[v]) {
            if (e.cap - e.flow > 0) {
                dist[v] = min(dist[v], dist[e.to] + 1);
            }
        }
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v) {
        for (auto& e : adj[v]) {
            if (excess[v] > 0) {
                Push(e);
            } else {
                break;
            }
        }

        if (excess[v] > 0) {
            if (count[dist[v]] == 1) {
                Gap(dist[v]);
            } else {
                Relabel(v);
            }
        }
    }

    T GetMaxFlow (int s, int t) {
        dist = vector <int>(n, 0), excess = vector<T>(n, 0), count = vector <int>(n + 1, 0);
        active = vector <bool>(n, false), B = vector <vector <int>>(n);
        b = 0;

        for (int i = 0; i < n; ++i) {
            for (auto& e : adj[i]) {
                e.flow = 0;
            }
        }

        for (auto& e : adj[s]) {
            excess[s] += e.cap;
        }

        count[0] = n;
        Enqueue(s);
        active[t] = true;

        while (b >= 0) {
            if (!B[b].empty()) {
                int v = B[b].back();
                B[b].pop_back();
                active[v] = false;
                Discharge(v);
            } else {
                b--;
            }
        }
        return excess[t];
    }

    void PreflowToFlow (int s, int t) {
        enum color {WHITE, GREY, BLACK};
        vector <color> rank (n, WHITE);
        vector <int> prev (n, -1);
        vector <typename vector <Edge <T>>::iterator> current;
        vector <int> st;
        for (int i = 0; i < n; ++i) {
            current.push_back (adj[i].begin());
        }

        for (int i = 0; i < n; ++i) {
            if (rank[i] == WHITE && excess[i] > 0 && i != s && i != t) {
                int r = i;
                rank[r] = GREY;
                do {
                    while (current[i] != adj[i].end()) {
                        auto e = current[i];
                        if (e->cap == 0 && e->cap - e->flow > 0 && e->to != s && e->to != t) {
                            int j = e->to;
                            if (rank[j] == WHITE) {
                                rank[j] = GREY;
                                prev[j] = i;
                                i = j;
                                break;
                            } else if (rank[j] == GREY) {
                                T amt = e->cap - e->flow;
                                do {
                                    amt = min (amt, current[j]->cap - current[j]->flow);
                                    if (j != i) {
                                        j = current[j]->to;
                                    }
                                } while (j != i);

                                do {
                                    e = current[j];
                                    e->flow += amt;
                                    adj[e->to][e->index].flow -= amt;
                                    j = e->to;
                                } while (j != i);

                                int restart = i;
                                for (j = current[i]->to; j != i; j = e->to) {
                                    e = current[j];
                                    if (rank[j] == WHITE || e->cap - e->flow == 0) {
                                        rank[current[j]->to] = WHITE;
                                        if (rank[j] != WHITE) {
                                            restart = j;
                                        }
                                    }
                                }

                                if (restart != i) {
                                    i = restart;
                                    current[i]++;
                                    break;
                                }
                            }
                        }
                        current[i]++;
                    }
                    if (current[i] == adj[i].end()) {
                        rank[i] = BLACK;
                        if (i != s) {
                            st.push_back(i);
                        }

                        if (i != r) {
                            i = prev[i];
                            current[i]++;
                        } else {
                            break;
                        }
                    }
                } while (true);
            }
        }

        while (!st.empty()) {
            int i = st.back();
            st.pop_back();

            auto e = adj[i].begin();

            while (excess[i] > 0) {
                if (e->cap == 0 && e->cap - e->flow > 0 ) {
                    T amt = min( excess[i], e->cap - e->flow );
                    e->flow += amt;
                    adj[e->to][e->index].flow -= amt;
                    excess[i] -= amt;
                    excess[e->to] += amt;
                }
                e++;
            }
        }
    }

    /*
        Finds minimal cut with source and sink
        Running time:
            O(|V|+|E|)
        Output:
            - cut, cut[u] =
                 0, if u belongs to the minimal cut containing source,
                 1, if u belongs to the minimal cut containing sink,
                -1, otherwise
    */

    T GetMinCut (int s, int t, vector <int>& cut) {
        T ret = GetMaxFlow(s, t);
        PreflowToFlow(s, t);
        cut = vector <int> (n, -1);
        queue<int> Q;

        Q.push(s);
        cut[s] = 0;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (auto& e : adj[u]) {
                if (cut[e.to] == -1 && e.cap - e.flow > 0) {
                    Q.push(e.to);
                    cut[e.to] = 0;
                }
            }
        }

        Q.push(t);
        cut[t] = 1;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (auto& e : adj[u]) {
                if (cut[e.to] == -1 && adj[e.to][e.index].cap - adj[e.to][e.index].flow > 0) {
                    Q.push(e.to);
                    cut[e.to] = 1;
                }
            }
        }

        return ret;
    }
};

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
		freopen("output.txt" , "w", stdout);
	#else
		// online submission
	#endif
	optimize();
	
	int n,kase = 1;

	while(cin >> n && n) {
		int s,t,m;
		cin >> s >> t >> m;
		s-- , t--;

		PushRelabel<ll> P(n);

		for(int i = 0; i < m; ++i) {
			int u,v,w;
			cin >> u >> v >> w;
			--u , --v;
			P.AddEdge(u,v,w);
			P.AddEdge(v,u,w);
		}

		cout << "Network " << kase++ << endl << "The bandwidth is " << P.GetMaxFlow(s,t) << "." << endl << endl;

	}
	
	return 0;
}






//?
