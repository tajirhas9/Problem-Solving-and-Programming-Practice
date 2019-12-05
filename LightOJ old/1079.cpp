#include <bits/stdc++.h>
using namespace std;

int dp[105][100005];
int m[1001];
double p[1001],max_p;
int n;
const double eps = 1e-9;

int solve(int idx, double p1,double p2) {
	int &ret = dp[idx][(p1*10000)];

	if(ret != -1)	return ret;


}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#else
		//nothing
	#endif

	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cin >> max_p >> n;

		for(int i = 0; i < n; ++i)
			cin >> m[i] >> p[i];

		memset(dp,-1,sizeof(dp));
		int ans = 0;
		for(int i = 0; i < n; ++i)
			ans = max(ans, solve(i,p[i],1-p[i]));

		cout << ans << endl;
	}

	return 0;
}