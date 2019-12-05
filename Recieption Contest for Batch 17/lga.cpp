/*
*
* Problem Name : Let's Go,Amigos!!!
* Author : Syed Tajir Hasnain
* ID : 1604081
* CSE, CUET.
*
*/

/*
*This problem can be solved in two steps.

First, You run a dijkstra to store the maximum number of people who can visit a node.
For example, in the test case 1 of the sample, for visiting node 4 , you need to go to node 2 with 3 vehicles,
then from node 2 to node 3 with 2 vehicles, then node 2 to node 4 with 4 vehicles.
So, if total number of people is greater than 2, then we can't travel from node 2 to node 3. So, the total journey is not possible.
Hence, to travel to node 4, maximum people can be 2.

After we have prestored all the values,during query-time, it is easy to run a binary search to check number of nodes that can't be visited with (c+1) people.
then the answer will be (total_nodes - nodes that can't be visited).

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N,E;
vector < pair < int , int > > graph[40001];

int cost_to_visit[40001];

void bfs() {
	int root = 1;
	queue < int > q;

	memset(cost_to_visit, -1 , sizeof(cost_to_visit));

	cost_to_visit[root] = 2000000000;

	q.push(root);

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto it : graph[u]) {
			int v = it.first;
			int w = min(cost_to_visit[u] ,  it.second) ;

			if(cost_to_visit[v] == -1 || w > cost_to_visit[v]) {
				cost_to_visit[v] = w;
				q.push(v);
			}
		}
	}

	cost_to_visit[root] = 0;
}

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
		freopen("output.out","w",stdout);
	#else
		//online judge
	#endif

	int T;

	scanf("%d",&T);

	for(int kase = 1; kase <= T; ++kase) {
		
		//Inputs

		scanf("%d %d" , &N, &E);

		for(int i = 0; i < E; ++i) {
			int u,v,w;

			scanf("%d %d %d" , &u, &v, &w);

			graph[u].push_back(make_pair( v , w ) );
			graph[v].push_back(make_pair( u , w ) );
		} 
		
		//Pre-store the minimum bike needed to be able to visit each node.

		bfs();

		//sort the nodes in ascending from minimum bike needed to maximum bike needed

		sort(cost_to_visit , cost_to_visit+N+1);


		int Q;

		scanf("%d" , &Q);

		printf("Case %d:\n", kase);

		while(Q--) {
			int c;
			scanf("%d",&c);
			c++;
			
			//The answer to the query is the number of nodes that can be reached with (c+1) bikes.

			int lo = 0 , hi = N;

			while(lo < hi) {
				int mid = (lo + hi +1) / 2;

				if(cost_to_visit[mid] >= c)
					hi = mid-1;
				else
					lo = mid;
		//		printf("lo= %d , hi = %d\n", lo,hi);
			}

			printf("%d\n", N-lo);
		}

		for(int i = 1; i <= N; ++i)
			graph[i].clear();

	}

	return 0;	
}