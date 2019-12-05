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

        RESET(dp,0);

        if(s[0] == 'R')
            dp[0][0] = 1;

        else if(s[0] == 'G')
            dp[0][1] = 1;
        
        else if(s[0] == 'B')
            dp[0][2] = 1;
        
        else
            dp[0][0] = dp[0][1] = dp[0][2] = 1;
    //    dbg(dp[0] , 3);

        ll len = strlen(s);

        bool flag = false;

        for(ll i = 0; i < len; ++i) {
            if(s[i] == 'W') {
                flag = true;
                break;
            }
        }

        if(!flag) {
            printf("Case %lld: %d\n" , kase , 0);
            continue;
        }

        s[len] = 'W';
        for(ll i = 1; i < len; ++i) {
            if(s[i] != 'W') {
                ll idx;
                if(s[i] == 'R')   idx = 0;
                else if(s[i] == 'G') idx = 1;
                else idx = 2;
                dp[i][idx] = modAdd( dp[i-1][ (idx+1)%3 ] , dp[i-1][ (idx+2)%3 ] );
  //              dbg(dp[i] , 3);
                continue;
            }
            if(s[i+1] != 'W') {
                ll idx;
                if(s[i+1] == 'R')   idx = 0;
                else if(s[i+1] == 'G') idx = 1;
                else idx = 2;
                dp[i][idx] = 0;
                dp[i][ (idx+1) % 3 ] = modAdd( dp[i-1][ (idx)%3 ] , dp[i-1][ (idx+2)%3 ] );
                dp[i][ (idx+2) % 3 ] = modAdd( dp[i-1][ (idx)%3 ] , dp[i-1][ (idx+1)%3 ] );
            }
            else {
                for(ll j = 0; j < 3; ++j)
                    dp[i][j] = modAdd( dp[i-1][ (j+1) % 3] , dp[i-1][ (j+2)%3 ] );
            }
//            dbg(dp[i] , 3);
        }

        ll ans = modAdd( modAdd( dp[len-1][0] , dp[len-1][1] )  , dp[len-1][2] );

        printf("Case %lld: %lld\n", kase, ans);
    }
    
    return 0;
}






//?
