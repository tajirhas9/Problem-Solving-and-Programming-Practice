#include <bits/stdc++.h>
using namespace std;


vector < vector < int > > g;
int n,m;


int main() {

	

	while(scanf("%d %d", &n, &m) == 2) {

		if(n == 0 && m == 0)
			break;

		g.assign(n+1, vector < int >());

		vector < int > indegree(n+1,0);

		for(int i = 1; i <= m; ++i) {
			int u,v;

			scanf("%d %d",&u,&v);

			g[u].push_back(v);
			
			indegree[v]++;	
		}

//		dbg(g);
		
		for(int i = 1; i <= n; ++i) {
			int u;
			for(int j = 1; j <= n; ++j) {
				if(indegree[j] == 0)  {
					if(i > 1)
						printf(" ");
					printf("%d", j);
					u = j;
					break;
				}
			}

			indegree[u] = -1;

			for(auto v : g[u])
				indegree[v]--;
	//		dbg(indegree);
		}
		printf("\n");
	}

	return 0;

}