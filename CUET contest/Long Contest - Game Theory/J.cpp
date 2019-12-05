#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {
        int n;

        cin >> n;

        int nimSum = -1;
        int x;

        for(int i = 0; i < n; ++i) {
            cin >> x;

            if(nimSum == -1)
                nimSum = x;
            else
                nimSum ^= x;
        }

        if(n == 1) {
            nimSum = (x > 1);
        }

        cout << "Case " << kase << ": ";

        cout << (nimSum ? "Alice" : "Bob") << endl;
    }
    return 0;
}
