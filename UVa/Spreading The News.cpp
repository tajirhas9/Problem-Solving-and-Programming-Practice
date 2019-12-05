#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000
vector <int> graph[3000];
queue <int> q;
int s,n,m,x,y,i,j,u,queries,level[3000],p[3000],ma=0,day=0;
int main()
{
    //freopen("Spreading The News.txt","r",stdin);
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> m;
        for(j=0; j<m; j++)
        {
            cin >> x;
            graph[i].push_back(x);
        }
    }
    cin >> queries;
    for(i=1; i<=queries; i++)
    {
        for(j=0; j<3000; j++)
        {
            level[j] = MAX;
            p[j] = 0;
        }
        cin >> s;
        q.push(s);
        level[s]=0;
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            for(j=0; j<graph[u].size(); j++)
            {
                if(level[graph[u][j]] == MAX)
                {
                    q.push(graph[u][j]);
                    level[graph[u][j]] = level[u]+1;
                    p[level[graph[u][j]]]++;
                    if(p[level[graph[u][j]]] > ma)
                    {
                        ma = p[level[graph[u][j]]];
                        day = level[graph[u][j]];
                    }
                }
            }
        }
        if(ma == 0)
            cout << ma << endl;
        else
            cout << ma << " " << day << endl;
        ma = 0;
        day = 0;
    }
    return 0;
}
