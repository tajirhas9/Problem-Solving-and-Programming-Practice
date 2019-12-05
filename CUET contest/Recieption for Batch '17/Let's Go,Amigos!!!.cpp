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
		
	}
}

int main() {
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
		
		dfs(1,0);

		int Q;

		scanf("%d" , &Q);

		while(Q--) {

		}
	}

	return 0;	
}