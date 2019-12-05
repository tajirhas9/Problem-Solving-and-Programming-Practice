#include<bits/stdc++.h> 

using namespace std;

typedef long long ll;

#define MOD 1000000007

#define RESET(a,b)    memset(a,b,sizeof(a))

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modAdd(ll a, ll b) { normal(a), normal(b); return (a+b)%MOD; }

#define R 1
#define G 2
#define B 3

ll dp[500005][4];

int main()
{
    
    ll T;

    scanf("%lld", &T);
    getchar();
    for(ll kase = 1; kase <= T; ++kase) {
        

        char s[500005];

        scanf("%s", s);

        ll len = strlen(s);

        if()

        for(int i = 0; i < len; ++i) {

        }
        
        printf("Case %lld: %lld\n", kase, ans);
    }
    
    return 0;
}






//?
