#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int MOD;

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
int main()
{
	
	ll x,y;

	int T;
	cin >> T;
	
	for(int kase = 1; kase <= T; ++kase) {
		
		cin >> x >> y;
		MOD = 10;

		cout << modPow(x,y) << endl;	
	}
	
	return 0;
}
