#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll a,b,n;
    int T;

    cin >> T;

    while(T--) {

        cin >> a >> b >> n;

        ll c = a^b;

        ll mod = n%3;

        if(mod==0)
            cout << a << endl;
        else if(mod == 1)
            cout << b << endl;
        else
            cout << c << endl;
    }
    return 0;
}

