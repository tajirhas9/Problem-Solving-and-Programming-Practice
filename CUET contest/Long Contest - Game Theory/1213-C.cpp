#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;

    cin >> T;

    while(T--) {
        long long n,m,a,d;

        cin >> n >> m;

        d = m;
        a = m;

        long long x = n/m;


        long long sum = a %10 + (a + (x-1)*d) % 10;
        sum *= x;
        sum /= 2;

        cout << sum << endl;
    }
    return 0;
}
