#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[200000];
queue <int> q;
int level[200000] = {0};
int main()
{
    int t,x,y,i,j,nodes,edges;
    cin >> t;
    while(t--)
    {
        cin >> nodes >> edges;
        for(i=1;i<=edges;i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        q.push(1);
        level[1] = 1;
        while(!q.empty())
        {
            for(j=0;j<graph[q.front()].size();j++)
            {
                if(level[graph[q.front()][j]] == 0)
                {
                    q.push(graph[q.front()][j]);
                    level[graph[q.front()][j]] = level[q.front()]+1;
                }
            }
            q.pop();
        }
        if(level[nodes] > 0)
            cout << level[nodes]-1 << endl;
        else
            cout << level[nodes] << endl;
        for(i=0;i<nodes;i++)
            level[i] = 0;
        for(i=0;i<=nodes;i++)
            graph[i].clear();
    }
    return 0;
}
