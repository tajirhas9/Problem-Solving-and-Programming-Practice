#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    string s,t;
    cin >> n >> m;
    cin >> s >> t;
    int pre=-1,suf=-1;
    if(n > m+1) {
        cout << "NO" << endl;
        return 0;
    }
    if(s == t) {
        cout << "YES" << endl;
        return 0;
    }
    for(int i = 0; i < n && i < m; ++i) {
        if(s[i] == '*') {
            pre = i;
            break;
        }
        else if(s[i] != t[i]) {
            cout << "NO" << endl;
            return 0;
        }
        if(i == m-1 && s[i+1] == '*') {
            cout << "YES" << endl;
            return 0;
        }
        else if(i == m-1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for(int i = n-1,j = m-1; i >= 0 && j >= 0; --i,--j) {
        if(s[i] == '*') {
            suf = j;
            break;
        }
        if(s[i] == t[j])    continue;
        else {
            cout <<"NO" << endl;
            return 0;
        }
        if(j == 0 && s[i-1] == '*') {
            cout << "YES" << endl;
            return 0;
        }
        else if(j == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
 //   cout << pre << " " << suf << endl;
    for(int i = pre; i <= suf; ++i) {
        if(t[i] >= 'a' && t[i] <= 'z')  continue;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
