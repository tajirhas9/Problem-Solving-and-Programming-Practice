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

//#define pb push_back
#define pb emplace_back
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

vi graph[1500005];
bool vis[1500005];
ll x,y;

void dfs(int u) {
	vis[u] = true;
	x++;
	y += graph[u].size();
	for(auto v : graph[u]) {
		if(!vis[v])
			dfs(v);
	}
}

void exit() {
	cout << "NO" << endl;
	exit(0);
}

int main() {
	
	optimize();

	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif


	int n,m;
	ll deg[150005];

	cin >> n >> m;

	for(int i = 0; i < m; ++i) {
		int u,v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
		deg[u]++;
		deg[v]++;
	}

	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			x = y = 0;
			dfs(i);
			
			if(x*(x-1) != y)
				exit();
		}
	}

	cout << "YES" << endl;

	return 0;
}