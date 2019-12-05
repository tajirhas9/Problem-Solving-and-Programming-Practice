#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;

    cin >> n >> k;

    vector < int > a(n+1);

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a.begin(),a.end());

    int mx = *max_element(a.begin(),a.end());


    vector < int > fp(mx*4+1,0) , lp(mx*4+1,0), cnt(mx*4+1,0);

    for(int i = 0; i <= n; ++i) {
        if(fp[a[i]] == 0)
            fp[a[i]] = i;
        lp[a[i]] = i;
        cnt[a[i]]++;
    }

    int res = 0;

    for(int i = 1; i <= n; ++i) {
       int f = a[i];

       while(f) {
            f /= 2;
            res++;
       }
    }

//    cout << res << endl;

    for(int i = 1; i <= mx; ++i) {
        int c = cnt[i];
        int step = 0;
        int p = 2;
        int pp = 1;

        while(c < k && i*p <= mx) {
            int l = min(i*p,mx) , r = min(mx, l+p-1);
//            cout << i << " " << l << " " << r << endl;
            if(l != i && lp[r] != 0 && fp[l] != 0) {
                int inc = (lp[r] - fp[l]+1) ;
                inc = min(inc, k-c);
                c += inc;
                step += inc*pp;
            }
//            cout << c << " " << step << " " << p << " " << pp << endl;
            p *= 2;
            pp++;
        }

        if(c >= k)
            res = min(res , step );
    }


    cout << res << endl;

    return 0;
}
