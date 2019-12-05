#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;

void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
ll modInverse(ll a) { return modPow(a, MOD-2); }
ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int n,k;

	cin >> n >> k;

	vector < int > dp(k+1,0);

	dp[0] = 1;

	for(int child = 0; child < n; ++child)  {
		int up_to;
		cin >> up_to;

		vector < int > dp2(k+1,0);

		for(int used = k; used >= 0; --used) {
			int L = used + 1 , R = used + min(up_to , k - used);
			if(L > R)	continue; 
			dp2[L] = modAdd(dp2[L] , dp[used]);
			if(R+1 <= k)
				dp2[R+1] = modSub(dp2[R+1] , dp[used]);
		}

		for(int i = 0; i <= k; ++i) {
			dp2[i] = modAdd(dp2[i] , dp2[i-1]);

			dp[i] = modAdd(dp[i] , dp2[i]);
		}
	}

	cout << dp[k] << endl;

	return 0;
}