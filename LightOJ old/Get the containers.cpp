#include <bits/stdc++.h>
using namespace std;

int n,m,a[1123],sum[1123];

bool isOk(int x) {
    int cnt=0,sum=0;

    for(int i = 1; i <= n; ++i) {
        if(a[i] > x)    return false;
        sum += a[i];
        if(sum > x) {
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    return cnt<=m;
}

int main() {
    #ifdef WIN64
        freopen("input.txt","r",stdin);
    #endif // WIN64
    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {
        memset(sum,0,sizeof(sum));
        cin >> n >> m;

        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum[i] = sum[i-1] + a[i];
        }
        int lo = 1 , hi = 1000010000;

        while(lo < hi) {
            int mid = (lo+hi)/2;

            if(isOk(mid))
                hi = mid;
            else
                lo = mid+1;
        }
        cout << "Case " << kase << ": ";
        cout << hi << endl;

    }

    return 0;
}
