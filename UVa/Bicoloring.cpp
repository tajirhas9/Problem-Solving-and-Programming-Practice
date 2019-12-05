#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10000
vector <int> edges[MAX];
queue <int> q;
int level[300] = {0};
int main()
{
    int flag=0,n,from,l,x,y,i,j;
    //freopen("bicoloring.txt","r",stdin);
    while(1)
    {
        flag = 0;
        for(i=0;i<300;i++)
            level[i] = 0;
        cin >> n;
        if(n == 0)
            return 0;
        cin >> l;
        for(i=1; i<=l; i++)
        {
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
            if(i==1)
            {
                level[x] = 1;
                q.push(x);
                from = q.front();
            }
        }
        while(!q.empty())
        {
            for(j=0; j<edges[q.front()].size(); j++)
            {
                if(level[edges[q.front()][j]] == 0)
                {
                    q.push(edges[q.front()][j]);
                    level[edges[q.front()][j]] = level[q.front()]+1;
                    //cout << "q.front() " << q.front() << endl;
                    //cout << level[edges[q.front()][j]] << endl;
                }
                else
                {
                    if(level[edges[q.front()][j]] == level[q.front()])
                    {
                        flag = 1;
                    }
                }
            }
            q.pop();
        }
        print:
        if(flag == 1)
            cout << "NOT BICOLORABLE." << endl;
        else
            cout << "BICOLORABLE." << endl;
        for(i=0;i<=300;i++)
        {
            edges[i].clear();
        }
    }
}
