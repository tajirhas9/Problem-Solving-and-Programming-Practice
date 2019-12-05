#include <bits/stdc++.h>
using namespace std;

typedef vector < int > vi;

int main() {
    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int T;

    cin >> T;

    while(T--) {
        int n;

        cin >> n;

        vi a(n);

        for(int i = 0; i < n; ++i)
            cin >> a[i];

        vi m(n);

        m[n-1] = a[n-1];

        for(int i = n-2; i >= 0; --i)
            m[i] = min(a[i] , m[i+1]);

        int cnt = 0;

        for(int i = 0; i < n; ++i)
            cnt += (m[i] < a[i]);

        cout << cnt << endl;
    }

    return 0;
}
