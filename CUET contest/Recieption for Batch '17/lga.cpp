#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,E;
vector < pair < int , int > > graph[40001];

int cost_to_visit[40001];

void dfs(int u , int val) {
	cost_to_visit[u] = val;

	for(auto it : graph[u]) {
		int v = it.first;
		int w = it.second;

		if(cost_to_visit[v] == -1)
			dfs(v,min(val,w));
	}
}

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online judge
	#endif

	int T;

	scanf("%d",&T);

	for(int kase = 1; kase <= T; ++kase) {
		scanf("%d %d" , &N, &E);

		for(int i = 0; i < E; ++i) {
			int u,v,w;

			scanf("%d %d %d" , &u, &v, &w);

			graph[u].push_back(make_pair( v , w ) );
			graph[v].push_back(make_pair( u , w ) );
		} 

		memset(cost_to_visit, -1 , sizeof(cost_to_visit));
		
		dfs(1,2000000000);
		cost_to_visit[1] = 0;

		for(int i = 1; i <= 4; ++i)
			printf("%d ", cost_to_visit[i]);
		printf("\n");

		sort(cost_to_visit , cost_to_visit+N+1);


		int Q;

		scanf("%d" , &Q);

		while(Q--) {
			int c;
			scanf("%d",&c);

			int ans = (int)(upper_bound(cost_to_visit, cost_to_visit+N+1 , c)-cost_to_visit);

			printf("%d\n", ans);
		}
	}

	return 0;	
}