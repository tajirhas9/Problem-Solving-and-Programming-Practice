#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000000
struct maze
{
    int mouse,time;
    bool operator < (const maze& p) const
    {
        return time >p.time;
    }
};
maze u,v;
int graph[200][200];
priority_queue <maze> q;
int n,m,e,t,i,j,test,k,x,y,w,d[200],total_mouse,te,xyz;
int main()
{
    freopen("Mice and Maze.txt","r",stdin);
    cin >> test;
    te = test;
    for(xyz=1;xyz<=test;xyz++)
    {
        total_mouse = 0;
        for(i=0;i<200;i++)
        {
            d[i] = MAX;
            for(j=0;j<200;j++)
                graph[i][j] = MAX;
        }
        cin >> n >> e >> t;
        cin >> m;
        for(i=1;i<=m;i++)
        {
            cin >> x >> y >> w;
            graph[y][x] = w;
        }
        u.mouse = e;
        u.time = 0;
        d[u.mouse] = 0;
        q.push(u);
        while(!q.empty())
        {
            u = q.top();
            q.pop();
            for(i=1;i<=n;i++)
            {
                if(graph[u.mouse][i] == MAX)     continue;
                v.mouse = i;
                v.time = graph[u.mouse][i] + u.time;
                if(v.time < d[v.mouse])
                {
                    d[v.mouse] = v.time;
                    q.push(v);
                }
            }
        }
        for(i=0;i<=n;i++)
        {
            if(d[i] <= t)
            {
                //cout << i << endl;
                total_mouse++;
            }
        }
        if(xyz != 1)
            cout << endl;
        cout << total_mouse << endl;
        /*for(i=0;i<=n;i++)
        {
            d[i] = MAX;
            graph[i].clear();
            cost[i].clear();
        }*/
    }
    return 0;
}
