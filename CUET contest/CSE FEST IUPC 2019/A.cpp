#include <bits/stdc++.h>
using namespace std;

const int inf = 2000000000;

class Dinic {
	int n,m,source,sink;

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

	Dinic(int nodes,int edges, vector < vector < int > > g, vector < vector < int > > cost) {
		n = nodes , m = edges;

		graph = g , c = cost;
		level.assign(n+1,-1);
		source = 1 , sink = n;
		f.assign(n+1,vector<int>(n+1,0));

	}

	int MaxFlow() {

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

		cin >> n >> m;

		vector < int > w(n+1);

		for(int i = 1; i <= n; ++i)
			cin >> w[i];

		vector < vector < int > > g(n+1) , c(n+1,vector<int>(n+1,0));

		for(int i = 0; i < m; ++i) {
			int u,v;
			cin >> u >> v;

			g[u].push_back(v);
			g[v].push_back(u);

			if(u == 1) {
				c[u][v] = w[v];
				c[v][u] = w[v];
			}
			else if(v == 1) {
				c[u][v] = w[u];
				c[v][u] = w[u];
			}
			else {
				c[u][v] = w[u];
				c[v][u] = w[v];
			}
		}

		Dinic dinic(n,m,g,c);

		cout << "Case #" << kase << ": " << min(w[n] , dinic.MaxFlow()) << endl;
	}

}