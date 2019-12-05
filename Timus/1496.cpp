#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
    #endif // ONLINE_JUDGE
    int n,x;
    map < string , int > m;
    string s;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> s;
        m[s]++;
    }

    map < string , int > :: iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        if(it->second > 1)
            cout << it->first << endl;
    }

    return 0;
}

