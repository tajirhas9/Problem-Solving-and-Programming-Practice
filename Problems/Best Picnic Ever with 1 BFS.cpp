#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define cin1(x) scanf("%d",&x)
#define cin2(x,y)   scanf("%d %d",&x,&y)
#define cin3(x,y,z) scanf("%d %d %d",&x,&y,&z)
int n,m,k;
vector<int> graph[1005];
queue<int> q;
int vis[1005];
int main()
{
    int T;
    cin1(T);
    for(int i=1;i<=T;i++)
    {
        memset(vis,0,sizeof(vis));
        int pos=0;
        cin3(k,n,m);
        for(int i=0;i<k;i++)
        {
            int x;
            cin1(x);
            q.push(x);
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin2(x,y);
            graph[x].push_back(y);
        }
        while(!q.empty())
        {
            int top;
            top = q.front();
            q.pop();
            vis[top]++;
            for(int i=0;i<graph[top].size();i++)
            {
                if(vis[graph[top][i]] < k)
                {
                    q.push(graph[top][i]);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i] == k)
            {
                //cout << i << endl;
                pos++;
            }
        }
        printf("Case %d: %d\n",i,pos);
        for(int i=0;i<=n;i++)
        {
            graph[i].clear();
        }
    }
    return 0;
}
