#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define BLACK 2
#define GREY 1
#define MAX 100000
void dfs(int s);
void reset();
vector <int> graph[10000];
int n,m,t=0,d[200],f[200],vis[200],task[200];
int main()
{
	//freopen("Ordering-Task.txt","r",stdin);
    int i,j,x,y;
    n=200;
    while(1)
    {
        reset();
        cin >> n >> m;
        if(n==0 && m==0)    return 0;
        for(i=0;i<m;i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
        }
        dfs(1);
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(f[j] > f[i])
                {
                    swap(f[j],f[i]);
                    swap(task[i],task[j]);
                }
            }
        }
        for(i=1;i<=n;i++)   cout << task[i] << " ";
        cout << endl;
    }
}
void dfs(int s)
{
    int i;
    t++;
    d[s] = t;
    vis[s] = GREY;
    for(i=0;i<graph[s].size();i++)
    {
        if(vis[graph[s][i]] == WHITE)
        {
            dfs(graph[s][i]);
        }
    }
    vis[s] = BLACK;
    t++;
    f[s] = t;
}
void reset()
{
    int i;
    for(i=0;i<=n;i++)
    {
        graph[i].clear();
        vis[i] = WHITE;
        d[i] = MAX;
        f[i] = MAX;
        task[i] = i;
    }
}
