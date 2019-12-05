#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//Bit Operations
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

ll n,h;
vector < ll > a,b;
ll dp[30][2][2];

ll solve(int i, int x, int y, ll score1, ll score2) {
    if(i == n) {
        if(score1>=h && score2>=h)
            return 1ll;
        return 0ll;
    }
//    cout << i << " " << x << " " << y << " " << score1 << " " << score2 << endl;
//    ll &ret = dp[i][x][y];
//    if(ret != -1)   return ret;

    ll ret = 0;

    ret += solve(i+1,0,1,score1,score2+b[i+1]);
    ret += solve(i+1,1,0,score1+a[i+1],score2);
    ret += solve(i+1,1,1,score1+a[i+1],score2+b[i+1]);

    return ret;
}

int main() {

    int T;

    scanf("%d",&T);

    for(int kase = 1; kase <= T; ++kase) {

        scanf("%lld %lld",&n,&h);

        a.resize(n+5);
        b.resize(n+5);

//        memset(dp,-1,sizeof(dp));

        for(int i = 1; i <= n; ++i)
            scanf("%lld",&a[i]);

        for(int i = 1; i <= n; ++i)
            scanf("%lld",&b[i]);

        ll ret = solve(0,0,0,0,0);

        printf("Case #%d: %lld\n",kase,ret);
    }
    return 0;
}
