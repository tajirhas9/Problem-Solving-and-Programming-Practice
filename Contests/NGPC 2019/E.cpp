#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 2e18+7;
class Dijkstra {

public:
	vector < vector < int > > g;
	vector < vector < ll > > w;
	int n,m,root;
	vector < ll > d;

	Dijkstra(int n, int m,int root) : n(n) , m(m) , root(root) {
		g.assign(n+1,vector < int >());
		w.assign(n+1,vector<ll>());
		d.assign(n+1,inf);
	}

	void AddEdge(int u, int v, ll x) {
		g[u].push_back(v);
		w[u].push_back(x);
	}

	void Build() {
		priority_queue < pair < ll , int > > q;

		q.push(make_pair(d[root] , root));
		d[root] = 0;

		while(!q.empty()) {
			pair < ll , int > top = q.top();	q.pop();
			int u = top.second;
			for(int i = 0 ; i < g[u].size(); ++i) {
				int v = g[u][i];
				if(d[u] + w[u][i] < d[v]) {
					d[v] = d[u] + w[u][i];
					q.push(make_pair(d[v],v));
				}
			}
		}
	}

	ll get(int u) {
		return d[u];
	}

};

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int T;
	scanf("%d",&T);
	
	for(int kase = 1; kase <= T; ++kase) {
		
		int n,m,x,q;

		scanf("%d %d %d %d", &n,&m,&x,&q);

		Dijkstra forward(n,m,x);
		Dijkstra backward(n,m,x);	
	
		for(int i = 1; i <= m; ++i) {
			int u,v;
			ll w;

			scanf("%d %d %lld",&u,&v,&w);

			forward.AddEdge(u,v,w);

			backward.AddEdge(v,u,w);
		}

		forward.Build();
		backward.Build();

		int u,v;

		printf("Case %d:\n", kase);
	
		while(q--) {
			int u,v;

			scanf("%d %d",&u,&v);

			ll x = backward.get(u);
			ll y = forward.get(v);

			if(x == inf || y == inf) {
				printf("Be seeing ya, John\n");
			}
			else {
				printf("%lld\n", x+y);
			}
		}
	}
	
}