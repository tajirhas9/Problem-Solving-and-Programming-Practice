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
//debug
#ifdef tajir
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
	os << "{";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
			os << *it;
	}
	return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
			os << *it;
	}
	return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << *it;
	}
	return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << it -> first << " = " << it -> second ;
		}
	return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () {
	cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
	for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
	cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
	cerr << arg << ' ';
	faltu(rest...);
}
#else
#define dbg(args...)
#endif // tajir

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
		freopen("output2.out","w",stdout);
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

	//	sort(cost_to_visit , cost_to_visit+N+1);


		int Q;

		scanf("%d" , &Q);

		printf("Case %d:\n", kase);

		while(Q--) {
			int c;
			scanf("%d",&c);
			c++;
			
			int ans = 0;
			for(int i = 1; i <= N; ++i) {
				if(cost_to_visit[i] >= c)
					ans++;
			}
			cout << ans << endl;
		}

		for(int i = 1; i <= N; ++i)
			graph[i].clear();

	}

//	timeStamp;

	return 0;	
}