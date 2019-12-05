#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
vector <int> edges[2000];
queue <int> q;
int main()
{
    int i,j,x,y,n,t,total=1,level[2000] = {0},last;
    cin >> t;
    while(t--)
    {
        total = 0;
        for(i=0;i<2000;i++)
            level[i] = 0;
        cin >> n;
        for(i=1;i<=n;i++)
        {
            cin >> x >> y;
            if(level[x] == 0) level[x] = 1;
            if(level[y] == 0) level[y] = 1;
        }
        for(i=0;i<2000;i++)
        {
            if(level[i] == 1)
                total++;
        }
        cout << total << endl;
    }
    return 0;
}
