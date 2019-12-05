#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {
        int n,m;

        cin >> n >> m;

        long long nimSum = -1;

        for(int i = 0; i < n; ++i) {
            long long sum = 0;
            for(int j = 0; j < m; ++j) {
                long long x;
                cin >> x;
                sum += x;
            }
            if(nimSum == -1)
                nimSum = sum;
            else
                nimSum ^= sum;
        }
        cout << "Case " << kase << ": ";
        cout << (nimSum ? "Alice" : "Bob") << endl;
    }
    return 0;
}
