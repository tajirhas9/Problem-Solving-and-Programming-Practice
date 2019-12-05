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

bool vis[3123456];

int main() {
    #ifndef ONLINE_JUDGE
//        freopen("input.txt","r",stdin);
    #else
        // online judge
    #endif // ONLINE_JUDGE

    int n,m;

    cin >> n >> m;
    int res = 0;

    queue < pii > q;

    q.push(mp(n,0));

    while(!q.empty()) {
        pii top = q.front();    q.pop();
 //       cout << top.F << " " << top.S << endl;
        if(top.F == m) {
            cout << top.S << endl;
            return 0;
        }

        int x = top.F*2;
        int y = top.F-1;

        if(x == m || y == m) {
            cout << top.S+1 << endl;
            return 0;
        }

        if(x >= 0 && !vis[x] && x <= 100000) {
            vis[x] = true;
            q.push(mp(x,top.S+1));
        }
        if(y >= 0 && !vis[y] && y <= 100000) {
            vis[y] = true;
            q.push(mp(y,top.S+1));
        }
    }

    return 0;
}
