#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;

class Dinic {
	int n,source,sink;

	vector < vector < int > > graph,f,c;
	vector < int > level;

	bool bfs() {

		level.assign(n+1,-1);

		queue < int > q;
		
		q.push(source);
		
		level[source] = 0;
		
		while(!q.empty()) {
	
			int top = q.front();
			q.pop();
		
			for(int i = 0; i < graph[top].size(); ++i) {
		
				int v = graph[top][i];
				
				if(level[v] == -1 && f[top][v] < c[top][v]) {
		
					level[v] = level[top] + 1;
		
					q.push(v);
		
				}
		
			}
		
		}
		return level[sink] != -1;
	}

	int dfs(int u , int flow) {
		
		if(flow == 0)	return flow;
		
		if(u == sink)	return flow;	

		for(int i = 0; i < graph[u].size(); ++i) {
		
			int v = graph[u][i];
		
			if(level[v] != level[u] + 1)	continue;		
															
		
			int pushed = dfs(v , min( flow , c[u][v] - f[u][v] ) );		
			
			if( pushed ) {												
		
				f[u][v] += pushed; 
		
				f[v][u] -= pushed;
		
				return pushed;
		
			}
		
		}
		
		return 0;
	}
public:

	Dinic(int nodes, vector < vector < int > > g, vector < vector < int > > cost) {
		n = nodes;

		graph = g , c = cost;
		level.assign(n+1,-1);
		f.assign(n+1,vector<int>(n+1,0));

	}

	int MaxFlow(int sc, int sk) {
		
		source = sc , sink = sk;

		int flow = 0;
		
		while(bfs()) {
			
			while(int pushed = dfs(source,inf)) {
				
				flow += pushed;
			}
		}
		
		return flow;
	}
};


int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		int n,m;

		cin >> n;

		vector < vector < int > > g(n+n+2),c(n+n+2,vector<int>(n+n+2,0));

		for(int i = 1; i <= n; ++i) {
			int w;
			cin >> w;
			g[i].push_back(i+n);
			c[i][i+n] = w;
		}

		cin >> m;

		for(int i = 1; i <= m; ++i) {
			int u,v,w;

			cin >> u >> v >> w;
			g[u+n].push_back(v);
			c[u+n][v] = w;
		}

		int b,d;

		cin >> b >> d;

		for(int i = 1; i <= b; ++i) {
			int u = 0 , v = 1;
			cin >> v;
			g[u].push_back(v);
			c[u][v] = inf;
		}

		for(int i = 1; i <= d; ++i) {
			int v = n+n+1 , u;

			cin >> u;
			g[u].push_back(v);
			c[u][v] = inf;
		}

		Dinic dinic(n+n+2,g,c);
	
		cout << "Case " << kase << ": " << dinic.MaxFlow(0,n+n+1) << endl;
	}
	

	return 0;
}