#include <bits/stdc++.h>
using namespace std;

#define all(c)  c.begin(),c.end()

int n,x,y;

int main() {

    cin >> n >> x >> y;

    vector < int > a(n,0);

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int cnt = 0;

    if(x > y) {
        cnt = n;
    }
    else {
        for(int i = 0; i < n; ++i)
            cnt += (a[i] <= x);
        cnt = (cnt/2)+(cnt%2);
    }

    cout << cnt << endl;

    return 0;
}
