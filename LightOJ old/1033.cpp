#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int dp[102][102];

int solve(int i, int j) {

	if(i >= j)	return 0;

	int &ret = dp[i][j];

	if(ret != -1)	return ret;

	if(s[i] == s[j])
		ret = solve(i+1,j-1);
	else
		ret = 1 + min(solve(i,j-1) , solve(i+1,j));
	return ret;
}

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#endif

	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		memset(dp,-1,sizeof(dp));

		cin >> s;
		n = s.size();
		
		cout << "Case " << kase << ": " << solve(0, n-1) << endl;
	}

	return 0;
}