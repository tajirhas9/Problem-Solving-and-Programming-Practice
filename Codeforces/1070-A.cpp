#include <bits/stdc++.h>
using namespace std;

bool vis[511][5101];
int d,s;
class node {
public:
    int rem,sum;
    string str;
    node(int dd=0, int ss=0, string p = "") {
        rem = dd , sum = ss , str = p;
    }
};

void bfs() {
    queue < node > q;

    node x(0,0,"");

    q.push(x);
    vis[0][0] = true;

    while(!q.empty()) {
        node top = q.front();
        q.pop();
        if(top.sum > s) continue;
   //     cout << top.str << endl;
        if(top.rem == 0 && top.sum == s) {
            cout << top.str << endl;
            return;
        }

        for(int i = 0; i < 10; ++i) {
            node p;
            int rem = (top.rem * 10 + i)%d;
            int sum = top.sum+i;

            if(!vis[rem][sum]) {
                vis[rem][sum] = true;
                q.push(node(rem,sum,top.str+(char)(i+'0')));
            }
        }
    }

    cout << -1 << endl;
}

int main() {

    cin >> d >> s;

    bfs();

    return 0;
}
