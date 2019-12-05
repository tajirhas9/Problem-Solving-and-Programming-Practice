#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//Bit Operations
inline bool checkBit(ll n, int i) { return n&(1LL<<i); }
inline ll setBit(ll n, int i) { return n|(1LL<<i);; }
inline ll resetBit(ll n, int i) { return n&(~(1LL<<i)); }

ll n,m;

vector < ll > a;

int main() {
    int T;

    scanf("%d",&T);

    for(int kase = 1; kase <= T; ++kase) {
        scanf("%lld %lld",&n,&m);

        a.assign(n,0);

        for(int i = 0; i < n; ++i)
            scanf("%lld",&a[i]);


        ll k = -1;

        for(int i = 1000; i >= 0; --i) {
            ll sum = 0;
            for(int j = 0; j < n; ++j) {
                sum += (a[j] ^ i);
            }

            if(sum <= m) {
                k = i;
                break;
            }
        }


        printf("Case #%d: %lld\n",kase, k);
    }
    return 0;
}

