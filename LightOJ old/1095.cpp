#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

#define RESET(a,b)	memset(a,b,sizeof(a))
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll ncr[1005][1005];

ll nCr(int n, int r) {
	if(r == 1)
		return n;

	if( n == r || r == 0)
		return 1;

	ll &ret = ncr[n][r];

	if(ret != -1)
		return ret;

	return ret = modAdd(nCr(n-1,r-1) , nCr(n-1,r));
}

ll dp[10005];

ll derange(ll x) {
	if(x == 0 || x == 2)
		return dp[x] = 1;
	if(x == 1)
		return dp[x] = 0;
	ll &ret = dp[x];

	if(ret != -1)	return ret;

	return ret = modMul(x-1 , modAdd(derange(x-1) , derange(x-2)));
}

int main()
{	
	int T;

	cin >> T;

	RESET(dp,-1);
	RESET(ncr,-1);

	for(int kase = 1; kase <= T; ++kase) {
		int n,m,k;

		cin >> n >> m >> k;

		int ans = 0;

		for(int i = 0; i <= n-m; ++i) {
			ans = modAdd(ans , modMul(nCr(n-m,i) , derange(n-(k+i))));
		}

		ans = modMul(ans , nCr(m,k));

		cout << "Case " << kase << ": " << ans << endl;
	}

	return 0;
}






//?
