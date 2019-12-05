#include<bits/stdc++.h>
using namespace std;

int n,m;
vector < vector < int > > adj;
vector < int > rr, lft,dist;

bool bfs () {
    queue <int> q;
    dist = vector <int>(n + 1, -1);
    for (int l = 1; l <= n; ++l) {
        if (rr[l] == 0) {
            dist[l] = 0;
            q.push(l);
        }
    }

    while (!q.empty()) {
        int l = q.front();
        q.pop();
        if (dist[0] == -1 || dist[l] < dist[0]) {
            for (int i = 0; i < adj[l].size(); ++i) {
                int r = adj[l][i];
                if (dist[lft[r]] == -1) {
                    dist[lft[r]] = dist[l] + 1;
                    q.push(lft[r]);
                }
            }
        }
    }
    return dist[0] != -1;
}

bool dfs (int l) {
    if (l != 0) {
        for (int i = 0; i < adj[l].size(); ++i) {
            int r = adj[l][i];
            if (dist[lft[r]] == dist[l] + 1 && dfs(lft[r])) {
                lft[r] = l;
                rr[l] = r;
                return true;
            }
        }
        dist[l] = -1;
        return false;
    }
    return true;
}

int Match () {
    rr = vector <int>(n + 1, 0);
    lft = vector <int>(m + 1, 0);
    int ret = 0;
    while (bfs()) {
        for (int l = 1; l <= n; ++l) {
            if (rr[l] == 0 && dfs(l)) {
                ret++;
            }
        }
    }
    return ret;
}

int main() {
	#ifdef tajir
//		freopen("input.txt","r",stdin);
	#else
		//online judge
	#endif

	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cin >> n >> m;

        adj.assign(n+n+2,vector < int > ());


		for(int i = 0; i < m; ++i) {
			int u,v;
			cin >> u >> v;

            adj[u].push_back(v);
            adj[v+n].push_back(u);
		}

        int match = Match();
 //       dbg(match);
	//	dbg(bipart.lft);
	//	dbg(bipart.rr);
	//	dbg(n-match);
		cout << "Case " << kase << ": " << max(match,(n-match)) << endl;
	}

	return 0;
}