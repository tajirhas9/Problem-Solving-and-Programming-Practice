#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
vector <int> graph[30];
queue <int> q;
int level[30] = {0};
int main()
{
    //freopen("risk.txt","r",stdin);
    int x,y,g,i,j,t,c=1;
    while(1)
    {
        for(i=1;i<=19;i++)
        {
            if((scanf("%d",&x)) == 1)
            {
                for(j=1;j<=x;j++)
                {
                    cin >> y;
                    graph[i].push_back(y);
                    graph[y].push_back(i);
                }
            }
            else
                return 0;
        }
        cin >> t;
        cout << "Test Set #" << c << endl;
        for(i=1;i<=t;i++)
        {
            cin >> x >> y;
            q.push(x);
            level[x] = 1;
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
            printf("%2d to %2d: %d\n",x,y,level[y]-1);
            for(j=0;j<30;j++)
                level[j] = 0;
        }
        cout << endl;
        for(i=0;i<30;i++)
        {
            graph[i].clear();
        }
        c++;
    }
    return 0;
}
