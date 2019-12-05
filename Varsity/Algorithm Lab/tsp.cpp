#include <bits/stdc++.h>
using namespace std;
#define inf 1000000000

typedef long long ll;

//Bit Operations

inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

int n;
int graph[10][10];
int dp[8][((1<<8)+100)];
stack < int > q;
int global_ans = inf;
int from;

int solve(int u , ll mask , stack < int > qq , int val, int st) {

	if(mask == (1<<(n+1))-1) {
		val += graph[qq.top()][st];
		if(val < global_ans) {
			global_ans = val;
			qq.push(st);
			while(!q.empty())
				q.pop();
			while(!qq.empty()) {
				int top = qq.top();
				qq.pop();
				q.push(top);
			}
		}
		return val;
	}

	int &ret = dp[u][mask];

	if(ret != -1)	return ret;
	
	ret = inf;
	if(u == 0) {
		qq.push(from);
		ret = solve(from , setBit(mask,from) , qq , 0 , from);
	}
	else {
		for(int i = 1; i <= n; ++i) {
			if(checkBit(mask,i))	continue;
			qq.push(i);
			ret = min(ret , solve(i, setBit(mask,i) , qq , val + graph[u][i] , st));
			qq.pop();
		}
	}
	return ret;
}

int main() {

	while(cin >> n) {
		
		memset(dp,-1,sizeof(dp));
		memset(graph,-1,sizeof(graph));

		for(int i = 0; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(i == 0) {
					graph[i][j] = 0;
					continue;
				}
				int w;
				cin >> w;
				graph[i][j] = w;
			}
		}

		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				if(i == j)	continue;
			}
		}
		cin >> from;
		stack < int > s;

		cout << "--------Output--------" << endl;

		cout << solve(0,1,s,0,0) << endl;

		while(!q.empty()) {
			int top = q.top();
			cout << top << " ";
			q.pop();
		}


	
		cout << endl;

	}



	return 0;
}