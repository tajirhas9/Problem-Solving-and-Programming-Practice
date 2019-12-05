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
    #ifdef tajir
        freopen("input.txt","r",stdin);
    #else
        //online submission
    #endif
    
    int T;

    scanf("%d",&T);

    for(int kase = 1; kase <= T; ++kase) {
        scanf("%lld %lld",&n,&m);

        a.assign(n,0);

        for(int i = 0; i < n; ++i)
            scanf("%lld",&a[i]);


        ll sum = 0 , k = 0;

        ll len = 0;

        ll ff = *max_element(a.begin() , a.end());
        ff = max(ff, m);

        for(len = 0; (1<<len) <= ff; ++len);

        --len;

        vector < ll > one(len+1,0) , zero(len+1,0);

        for(int i = 0; i <= len; ++i) {
            for(int j = 0; j < n; ++j) {
                if(checkBit(a[j],i))
                    one[i]++;
                else
                    zero[i]++;
            }
        }

        for(int i = len; i >= 0; --i) {
            ll f0 = zero[i];
            ll _sum0 = sum + (f0 << i );
            ll f1 = one[i];
            ll _sum1 = sum + (f1 << i);

//            cout << (f1<<i) << endl;

            if(_sum0 > m) {
                k = k;
                sum = _sum1;
            }
            else {
                k = setBit(k,i);
                sum = _sum0;
            }

 //           cout << f0 << " " << f1 << " " << _sum0 << " " << _sum1 << " " << sum << " " << k << endl;
        }

        ll x = a[0] ^ k;

        for(int i = 1; i < n; ++i)
            x += (a[i] ^ k);

        if(x > m)
            k = -1;


        printf("Case #%d: %lld\n",kase, k);
    }
    return 0;
}
