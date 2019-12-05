#include <bits/stdc++.h>
using namespace std;

vector < vector < int > > v;

int main() {

    int n,N;

    cin >> n;

    N = n*n;

    v.resize(n+1,vector <int >(n+1,0));

    vector < int > rowXor(n+1,0) , colXor(n+1,0);
    vector < bool > vis(N+1,false);

    int msb = log2(N);

    int p = N-1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j, --p)
            cout << p << " ";
        cout << endl;
    }
    return 0;
}
