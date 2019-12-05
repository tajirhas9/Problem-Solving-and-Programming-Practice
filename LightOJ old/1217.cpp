#include <bits/stdc++.h>
using namespace std;

int n;
int a[1123];
int dp[1123];

int main() {
	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cin >> n;

		for(int i = 1; i <= n; ++i)
			cin >> a[i];

		memset(dp,-1,sizeof(dp));

		dp[0] = 0;
		dp[1] = a[1];
		dp[2] = 0;

		for(int i = 3; i < n-1; ++i)
			dp[i] = max(dp[i-1] , dp[i-2] + a[i]);
		int p1 = dp[n-1];

		memset(dp,-1,sizeof(dp));

		dp[1] = 0;
		dp[0] = 0;
		for(int i = 2; i <= n; ++i)
			dp[i] = max(dp[i-1] , dp[i-2] + a[i]);

		int p2 = dp[n];

		cout << "Case " << kase << ": " << max(p1,p2) << endl;
	}
	return 0;
}
