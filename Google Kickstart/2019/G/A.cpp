#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    long long T;

    scanf("%lld",&T);

    for(long long kase = 1; kase <= T; ++kase) {
        long long n,m,q;
        scanf("%lld %lld %lld", &n,&m,&q);

        vector < long long > p(m);

        for(long long i = 0; i < m; ++i)
            scanf("%lld",&p[i]);

        vector < long long > res(n+5, 0);

        for(int i = 0; i < m; ++i) {
            long long x = p[i];
            for(long long i = 1; i * i <= x; ++i) {
                if(x % i == 0) {
                    long long a = i , b = x/i;
                    res[a]++;

                    if(a != b)
                        res[b]++;
                }
            }
        }

        long long sum = 0;

        while(q--) {
            ll x;
            scanf("%lld", &x);

            sum += max(0ll,( (n/x) - res[x]));
        }


        printf("Case #%lld: %lld\n", kase,sum);
    }


    return 0;
}
