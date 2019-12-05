#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {
        long long x;
        long long d;

        cin >> d >> x;

        bool flag = false;
        bool flag1 = true;
        if(x == 0)
            flag1 = false;
        cout << "Case " << kase << ": ";

        if(x > ((1ll<<(d+1ll)) - 1ll) || !flag1) {
            cout << "NO" << endl;
            continue;
        }

        for(ll step = 1 , a = (1ll<<d) ; step <= d+1 && !flag; ++step , a /= 2) {
            ll dd = a*2;
 //           cout << a << " " << dd << endl;
            if( (x >= a) && (x-a) % dd == 0) {
                cout << "YES " << step << endl;
                flag = true;
                continue;
            }
        }
    }
    return 0;
}
