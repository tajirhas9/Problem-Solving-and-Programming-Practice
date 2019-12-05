#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
ll dp[100][100];

ll solve(int i, int j) {
	if(j < i)	return 0;
	if(i == j)	return 1;
	ll &ret = dp[i][j];

	if(ret != -1)	return ret;

	if(s[i] == s[j])
		ret = 1 + solve(i+1,j) + solve(i, j-1);
	else
		ret = solve(i+1,j) + solve(i,j-1) - solve(i+1,j-1);
	return ret;
}

int main() {

	int T;

	cin >> T;

	for(int kase = 1; kase <= T; ++kase) {
		cin >> s;
		
		memset(dp,-1,sizeof(dp));

		cout << "Case " << kase << ": " << solve(0,s.size()-1) << endl;
	}

	return 0;
}