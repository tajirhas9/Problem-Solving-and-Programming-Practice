#include <bits/stdc++.h>
using namespace std;

#define mp  make_pair
#define pb  push_back
#define F   first
#define S   second

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

    bool flag = false;

    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        flag |= x;
    }

    if(flag)
        cout << "HARD" << endl;
    else
        cout << "EASY" << endl;

    return 0;
}

