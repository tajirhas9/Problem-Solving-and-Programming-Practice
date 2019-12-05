#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector < ll > vl;
typedef vector < pair < ll , ll > > vll;

#define pb push_back
#define all(c)	c.begin(),c.end()
#define F first
#define S second
#define mp make_pair

int main()
{
	
	#ifdef tajir
		freopen("input.txt", "r", stdin);
		freopen("output.txt","w", stdout);
	#else
		// online submission
	#endif
	
	ll n,w;
	ll T;

	bool first = true;

	while(cin >> T >> w) {
		cin >> n;

		vector < ll > d(n+1) , v(n+1);

		vector < vector < ll > > dp(n+1, vl(T+1,0));

		for(int i = 1; i <= n; ++i) {
			cin >> d[i] >> v[i];
		}

		for(int i = 0; i <= n; ++i)
			dp[0][i] = 0;

		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= T; ++j) {
				int cost = 3 * d[i] * w;
				if(j < cost)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = max(dp[i-1][j] , dp[i-1][j-cost] + v[i]);
			}
		}

		if(!first) {
			cout << endl;
		}
		else
			first = false;

		cout << dp[n][T] << endl;

		vll res;

		int i = n , j = T;

		while(i > 0 && j > 0) {
//			while(dp[i][j] == dp[i][j-1])
//				--j;
//			dbg(i,j);

//			if(i == 1 && j > 0) {
//				res.pb(mp(d[i] , v[i]));
//				--i;
//				continue;
//			}
			if(dp[i][j] == dp[i][j-1])
				--j;
			else if(dp[i][j] == dp[i-1][j])
				i--;
			else {
				res.pb( mp(d[i] , v[i]));
				j -= (3 * d[i] * w);
				--i;
			}
//			dbg(i,j);
		}

//		dbg(res);

		reverse(all(res));

		cout << res.size() << endl;


		for(auto x : res)
			cout << x.F << " " << x.S << endl;
	}
	
	return 0;
}
