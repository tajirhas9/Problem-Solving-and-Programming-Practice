#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {
        double r;

        cin >> r;
        cout << "Case " << kase << ": ";
        cout << fixed << setprecision(4) << ( (r*r) / 4.0) << endl;
    }
    return 0;
}
