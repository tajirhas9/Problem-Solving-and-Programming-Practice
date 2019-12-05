#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;

    while(cin>>n) {
        bool flag = true;
        long long p = 1;

        while(p < n) {
            p *= 9;
            if(p >= n) {
                flag = true;
                break;
            }
            p *= 2;
            if(p >= n) {
                flag = false;
                break;
            }
        }

        cout << (flag ? "Stan wins." : "Ollie wins.") << endl;
    }
    return 0;
}
