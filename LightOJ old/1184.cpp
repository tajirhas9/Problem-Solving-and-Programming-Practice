#include<bits/stdc++.h> 
using namespace std;

#define RESET(a,b)	memset(a,b,sizeof(a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


/*
    Implementation of Hopcroft-Karp algorithm of finding maximum matching
    Running time:
        O(|E||V|^{1/2})
    Usage:
        - add edges by AddEdge()
        - indexing is 1-based
        - call Match() to generate the macimum matching
        - MinimumVertexCover() finds a vertex cover of minimum size
        - Maximum independent set is the complement of minimum vertex cover
    Input:
        - graph, constructed using AddEdge()
    Output:
        - number of matching in the maximum matching
        - right, node l of the left is matched with node right[l] of the right, (right[l] = 0 if unmatched)
        - left, node r of the right is matched with node left[r] of the left, (left[r] = 0 if unmatched)
    Todo:
        - Probably convert to 0-base indexing
    Tested Problems:
        - UVA: 12880
*/

struct HopcroftKarp {
    int n, m;
    vector <vector <int>> adj;
    vector <int> right, left;
    vector <int> dist;

    HopcroftKarp (int n, int m): n(n), m(m), adj(n + 1) {}

    void AddEdge (int l, int r) {
        adj[l].push_back(r);
    }

    bool bfs () {
        queue <int> q;
        dist = vector <int>(n + 1, -1);
        for (int l = 1; l <= n; ++l) {
            if (right[l] == 0) {
                dist[l] = 0;
                q.push(l);
            }
        }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            if (dist[0] == -1 || dist[l] < dist[0]) {
                for (auto& r : adj[l]) {
                    if (dist[left[r]] == -1) {
                        dist[left[r]] = dist[l] + 1;
                        q.push(left[r]);
                    }
                }
            }
        }
        return dist[0] != -1;
    }

    bool dfs (int l) {
        if (l != 0) {
            for (auto& r : adj[l]) {
                if (dist[left[r]] == dist[l] + 1 && dfs(left[r])) {
                    left[r] = l;
                    right[l] = r;
                    return true;
                }
            }
            dist[l] = -1;
            return false;
        }
        return true;
    }

    int Match () {
        right = vector <int>(n + 1, 0);
        left = vector <int>(m + 1, 0);
        int ret = 0;
        while (bfs()) {
            for (int l = 1; l <= n; ++l) {
                if (right[l] == 0 && dfs(l)) {
                    ret++;
                }
            }
        }
        return ret;
    }

    /*
        Finds minimum vertex cover
        Running time:
            O(|V|+|E|)
        Output:
            - leftCover, leftCover[l] is true iff node l of the left side is in the minimum vertex cover
            (not in the maximum independent set)
            - leftCover, rightCover[r] is true iff node r of the right side is in the minimum vertex cover
            (not in the maximum independent set)
    */

    void MinimumVertexCover (vector <bool>& leftCover, vector <bool>& rightCover) {
        leftCover = vector <bool>(n + 1, true), rightCover = vector <bool>(m + 1, false);
        queue <int> q;
        dist = vector <int>(n + 1, -1);
        for (int l = 1; l <= n; ++l) {
            if (right[l] == 0) {
                dist[l] = 0;
                q.push(l);
            }
        }

        while (!q.empty()) {
            int l = q.front();
            q.pop();
            leftCover[l] = false;
            if (dist[0] == -1 || dist[l] < dist[0]) {
                for (auto& r : adj[l]) {
                    if (dist[left[r]] == -1) {
                        dist[left[r]] = dist[l] + 1;
                        rightCover[r] = true;
                        q.push(left[r]);
                    }
                }
            }
        }
    }
};

struct person {
	int height,age , divorced;
};
person men[100] , women[100];

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();
	
	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		int n,m;

		HopcroftKarp bipart(100,10000);

		cin >> m >> n;
		
		for(int i = 1; i <= m; ++i)
			cin >> men[i].height >> men[i].age >> men[i].divorced;
		
		for(int i = 1; i <= n; ++i)
			cin >> women[i].height >> women[i].age >> women[i].divorced;

		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(abs(men[i].age - women[j].age) <= 5 &&
					abs(men[i].height - women[j].height) <= 12 &&
					!(men[i].divorced ^ women[j].divorced)) 
						bipart.AddEdge(i,j);
			}
		}

		cout << "Case " << kase << ": " << bipart.Match() << endl;
	}
	
	return 0;
}






//?
