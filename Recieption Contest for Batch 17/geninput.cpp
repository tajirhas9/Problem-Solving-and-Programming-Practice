#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    fstream input;
    input.open("./input.in",ios::out|ios::trunc);
    int T;
    input << 10 << endl;
    srand(time(0));
    map < pair < int , int >  , bool > nm;
    for(int i = 0; i < 10; ++i) {
        int n = 40000;
        int m = rand() % min(15000,(n*(n-1) )) ;
        m++;
        if(nm.find(make_pair(n,m)) != nm.end()) {
            --i;
            continue;
        } 
        nm[make_pair(n,m)] = true;
        input << n << " " << m << endl;
        map < pair < pair < int , int > , int > , bool > uvw;
        for(int j = 0; j < m; ++j) {
            int u = rand() % n;
            int v = rand() % n;
            int w = rand() % 1000000000;
            u++ , v++ , w++;
            if(uvw.find(make_pair(make_pair(u,v),w)) != uvw.end())  {
                --j;
                continue;
            }
            uvw[make_pair(make_pair(u,v),w)] = true;
            input << u << " " << v << " " << w << endl;
        }
        int q = 100000;
        input << q << endl;
        map < int , bool > qq;
        while(q--) {
            int c = rand() % 1000000000;
            ++c;
            if(qq.find(c) != qq.end())  {
                ++q;
                continue;
            }
            qq[c] = true;
            input << c << endl;
        }
    }
    input.close();
    cout << "done" << endl;
    timeStamp;
    return 0;
}
