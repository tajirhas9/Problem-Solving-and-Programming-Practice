#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 10000007

void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
ll modInverse(ll a) { return modPow(a, MOD-2); }
ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll a, b, c, d, e, f;
ll dp[10005];

ll fn( ll n ) {
    ll &ret = dp[n];
    if(ret != -1)   return ret;

    if( n == 0 ) return ret = a;
    if( n == 1 ) return ret = b;
    if( n == 2 ) return ret = c;
    if( n == 3 ) return ret = d;
    if( n == 4 ) return ret = e;
    if( n == 5 ) return ret = f;

    return ret = modAdd( fn(n-1) , modAdd ( fn(n-2) , modAdd( fn(n-3) , modAdd( fn(n-4) ,modAdd( fn(n-5) , fn(n-6) )))) );
}
int main() {
    #ifdef tajir
        freopen("input.txt","r",stdin);
    #else
        //online submission
    #endif
    
    ll n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {
        
        memset(dp,-1,sizeof(dp));

        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n) % MOD);
    }
    return 0;
}