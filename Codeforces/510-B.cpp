#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second
#define mp make_pair

char adj[100][100] , c;
bool ans = false , vis[100][100];
int fx[] = {0 , 0 , +1 , -1};
int fy[] = {1 , -1 , 0 , 0};
int n,m;
pii root;

bool dfs(pii u, int cnt) {
//	cout << "entering " << u.F << "," << u.S << endl;
	bool p = false;
	vis[u.F][u.S] = true;
	for(int i = 0; i < 4; ++i) {
		pii v;
		v.F = u.F + fx[i];
		v.S = u.S + fy[i];
		if(v.F >= 0 && v.F < n && v.S >= 0 && v.S < m && !(v.F == u.F && v.S == u.S) ) {
			if(adj[v.F][v.S] == c) {
				if(!vis[v.F][v.S])
					p |= dfs(v,cnt+1);
				else if(cnt > 3 && v.F == root.F && v.S == root.S){
			//		cout << "returning true for " << v.F << "," << v.S << endl;
					return true;
				}
			}
		}
	}
	return p;
}

int main() {
	
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#endif

	string s;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		for(int j = 0; j < m; ++j) {
			adj[i][j] = s[j];
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			
			memset(vis,false,sizeof(vis));

			c = adj[i][j];
			root.F = i , root.S = j;
			ans |= dfs( mp(i,j), 1);
			if(ans)	break;
		}
	}

	cout << ((ans) ? "Yes" : "No") << endl;

	return 0;
}