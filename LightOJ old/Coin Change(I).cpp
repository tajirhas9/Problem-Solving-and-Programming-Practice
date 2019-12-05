#include <bits/stdc++.h>
using namespace std;
int dp[1001][51][21]
int main() {
    freopen("input.txt","r",stdin);
    int T,n,x,c[51],a[51];

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {
        memset(dp,0,sizeof(dp));
        cin >> n >> x;
        for(int i = 0; i < n; ++i)  cin >> a[i];
        for(int i = 0; i < n; ++i)  cin >> c[i];



        cout << "Case " << kase << ": " << dp[x] << endl;
    }

    return 0;
}
