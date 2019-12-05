#include <bits/stdc++.h>
using namespace std;

#define mp          make_pair
#define pb          push_back
#define F           first
#define S           second
#define all(c)      c.begin(),c.end()

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

    vi p(5);

    cin >> p[1] >> p[2] >> p[3] >> p[4];

    string s;
    cin >> s;

    int res = 0;

    int n = s.size();

    for(int i =0;i < n; ++i) {
        int x = s[i] - '0';

        res += p[x];
    }

    cout << res << endl;

    return 0;
}

