#include <bits/stdc++.h>
using namespace std;

int n,k,a[1005];

bool isOk(int x) {
    int cnt=0,sum=0;

    for(int i = 0; i < n; ++i) {
        sum += a[i];
        if(sum > x) {
            cnt++;
            sum = a[i];
        }
    }
    cnt++;
    return cnt<=k;
}

int main() {

    int T;
    scanf("%d",&T);
    for(int kase = 1; kase <= T; ++kase)  {
        int lo=0,hi=0;
        scanf("%d %d",&n,&k);
        n++,k++;
        for(int i = 0; i < n; ++i) {
            scanf("%d",&a[i]);
            hi += a[i];
            lo = max(lo,a[i]);
        }
        int ans = lo;
        while(lo < hi) {
            int mid = (lo+hi)/2;

            if(isOk(mid))
                hi = mid;
            else
                lo = mid+1;
        }
        ans = hi;
        int cnt = k,sum=0;
        printf("Case %d: %d\n",kase,ans);
        for(int i = 0; i < n; ++i) {
            sum += a[i];
            if(sum > ans || n-i+1 == cnt) {
                printf("%d\n",sum-a[i]);
                sum = a[i];
                cnt--;
            }
        }
        printf("%d\n",sum);
    }

    return 0;
}
