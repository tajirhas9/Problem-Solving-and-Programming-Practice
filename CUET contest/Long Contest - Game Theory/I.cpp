#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {
        int n;

        cin >> n;

        vector < int > a(n),b(n);

        for(int i = 0; i < n; ++i)
            cin >> a[i];

        for(int i = 0; i < n; ++i)
            cin >> b[i];

        int nimSum = 0;

        for(int i = 0; i < n; ++i)
            nimSum ^= (b[i] - a[i] - 1);

        cout << "Case " << kase << ": ";
        cout << (nimSum ? "white " : "black ") << "wins" << endl;
    }
    return 0;
}
