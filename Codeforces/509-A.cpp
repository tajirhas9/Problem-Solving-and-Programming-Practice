#include <bits/stdc++.h>
using namespace std;

#define mp  make_pair
#define pb  push_back
#define F   first
#define S   second
#define all(c)  c.begin(),c.end()

typedef long long           ll;
typedef vector < int >      vi;
typedef vector < ll >       vl;
typedef pair < int , int >  pii;
typedef pair < ll , ll >    pll;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #else
        // online judge
    #endif // ONLINE_JUDGE

    int n;

    cin >> n;

    vector < vi >  v(n, vi(n,0));

    for(int i = 0; i < n; ++i)
        v[i][0] = v[0][i] = 1;

    for(int i = 1; i < n; ++i)
        for(int j = 1; j < n; ++j)
            v[i][j] = v[i-1][j] + v[i][j-1];

    int res = 1;

    for(int i = 0; i < n; ++i)
        res = max(res , *max_element(all(v[i])));

    cout << res << endl;

    return 0;
}

