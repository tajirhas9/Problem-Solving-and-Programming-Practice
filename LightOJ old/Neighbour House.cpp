#include <bits/stdc++.h>
using namespace std;
int main() {
//    freopen("input.txt","r",stdin);
    int T;
    int n,a[22][3],dp[22][3];

    cin >> T;
    for(int kase = 1; kase <= T; ++kase) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 3; ++j)
                cin >> a[i][j];
        }
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 3; ++j)
                dp[i][j] = a[i][j] + min(dp[i-1][ (j+1)%3 ] , dp[i-1][(j+2)%3]);
        }
        int ans = min(dp[n][0] , min(dp[n][1] , dp[n][2] ) );
        printf("Case %d: %d\n",kase, ans);
    }

    return 0;
}
