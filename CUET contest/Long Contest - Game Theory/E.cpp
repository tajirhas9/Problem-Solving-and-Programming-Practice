#include <bits/stdc++.h>
using namespace std;

typedef vector < int > vi;
typedef vector < vi > vvi;

vvi dp;
vi a;

int solve(int l, int r) {
    if(l > r)   return 0;

    int &ret = dp[l][r];

    if(ret != -1)   return ret;

    ret = -INT_MAX;

    int sum = 0;

    for(int i = l; i <= r; ++i) {
        sum += a[i];
        ret = max(ret , sum-solve(i+1,r));
    }
    sum = 0;

    for(int i = r; i >= l; --i) {
        sum += a[i];
        ret = max(ret , sum-solve(l,i-1));
    }

    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
 //       freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int n;

    while(cin >> n && n) {
        a.assign(n+1,0);
//        cout << n << endl;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];

        dp.assign(n+1,vi(n+1,-1));

        cout << solve(1,n) << endl;
    }

    return 0;
}

