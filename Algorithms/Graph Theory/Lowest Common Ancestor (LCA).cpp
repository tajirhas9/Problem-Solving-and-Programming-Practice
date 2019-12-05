/*
* The nodes are to be 0-based.
*/

class LowestCommonAncestor {
	
	vector < vector < int > > graph;
	int nodes;

	vector < int > size , depth , tin , tout;
	int timer,max_anc=0;
	vector < vector < int > > anc;
	vector < bool > vis;

	void dfs(int u , int par = 1 , int d = 0) {
		vis[u] = true;
		depth[u] = d;
		tin[u] = timer++;
		size[u] = 1;
		anc[u][0] = par;

		for(int i = 1; i < max_anc; ++i)
			anc[u][i] = anc[ anc[u][i-1] ][i-1];

		for(int i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i];
			if(!vis[v]) {
				dfs(v, u , d+1 );
				size[u] += size[v];
			}
		}

		tout[u] = timer++;
	}


	bool ancestor(int a, int b) {
		return ( (tin[a] <= tin[b] ) && (tout[b] <= tout[a] ) );
	}

	int go_up(int a, int b) {
		for(int i = max_anc-1 ; i >= 0; --i) {
			if(!ancestor(anc[a][i],b))
				a = anc[a][i];
		}
		return a;
	}
public:
	LowestCommonAncestor(vector < vector < int > > g, int n) {
		max_anc = log2(n);
		nodes = n;
		graph = g;

		size.assign(n,0);
		depth.assign(n,0);
		tin.assign(n,0);
		tout.assign(n,0);
		anc.assign(n,vi(max_anc));
		vis.assign(n,false);
		timer = 0;

		dfs(0);
	}
	int lca(int a, int b) {
		if(ancestor(a,b))
			return a;
		else if(ancestor(b,a))
			return b;
		else
			return anc[go_up(a,b)][0];
	}
};
