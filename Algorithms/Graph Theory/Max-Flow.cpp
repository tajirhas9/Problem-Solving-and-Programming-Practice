const int inf = 2000000000;

/*
*Add a super sink if there are more than one sinks that will connect all other sinks 
*/

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
