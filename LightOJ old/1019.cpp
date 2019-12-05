#include <bits/stdc++.h>
using namespace std;

#define inf 2000000000
#define pb push_back

int main() {
	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int n,m;

		cin >> n >> m;
	
		vector < int > d(n+10,inf);
		vector < int > g[n+10] , c[n+10];
		
		for(int i = 0; i < m; ++i) {
			int u,v,w;
			cin >> u >> v >> w;
			g[u].pb(v);
			g[v].pb(u);
			c[u].pb(w);
			c[v].pb(w);
		}
		d[1] = 0;
		queue < int > q;

		q.push(1);

		while(!q.empty()) {
			int u = q.front();
			q.pop();

			for(int i = 0; i < g[u].size(); ++i) {
				int v = g[u][i];
				int w = c[u][i];

				if(d[v] > d[u] + w) {
					d[v] = d[u] + w;
					q.push(v);
				}
			}
		}

		cout << "Case " << kase << ": ";
		if(d[n] == inf)
			cout << "Impossible" << endl;
		else
			cout << d[n] << endl;
	}

	return 0;
}
