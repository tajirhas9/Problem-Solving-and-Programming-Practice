#include <bits/stdc++.h>
using namespace std;

int main() {

	long long  dp[31234];
	long long  coin[] = {1,5,10,25,50};

	dp[0] = 1;

	for(long long  j = 0; j < 5; ++j) {
//		dbg(j);
		for(long long  i = coin[j] , root = 0; i <= 30000; ++i , ++root) {
			dp[i] += dp[root];
//			dbg(i,root,dp[i] , dp[root]);
		}
	}

	long long  n;

	while(cin >> n ) {
		long long ans = (n==0) ? 0 : dp[n];
		if(dp[n] == 1) 
			cout << "There is only 1 way to produce " << n << " cents change." << endl;
		else
			cout << "There are " << ans << " ways to produce " << n << " cents change." << endl;
	}

	return 0;
}