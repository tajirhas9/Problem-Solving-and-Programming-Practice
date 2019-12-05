#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 100000
struct server
{
    int computer,money;
    bool operator < (const server& p) const
    {
        return money > p.money;
    }
};
server u,v;
vector <int> graph[50000],cost[50000];
priority_queue <server> q;
int t,x,y,w,i,j,k,d[50000],s,n,m,test;
int main()
{
    //freopen("Sending email.txt","r",stdin);
    cin >> test;
    for(i=1; i<=test; i++)
    {
        for(j=0;j<50000;j++)
            d[j] = MAX;
        cin >> n >> m >> s >> t;
        for(j=1;j<=m;j++)
        {
            cin >> x >> y >> w;
            graph[x].push_back(y);
            graph[y].push_back(x);
            cost[x].push_back(w);
            cost[y].push_back(w);
        }
        u.computer = s;
        u.money = 0;
        q.push(u);
        while(!q.empty())
        {
            u = q.top();
            q.pop();
            for(j=0;j<graph[u.computer].size();j++)
            {
                v.computer = graph[u.computer][j];
                v.money = cost[u.computer][j] + u.money;
                if(v.money < d[v.computer])
                {
                    d[v.computer] = v.money;
                    q.push(v);
                }
            }
        }
print:
        if(d[t] == MAX)    cout << "Case #" << i << ": unreachable" << endl;
        else    cout << "Case #" << i << ": " << d[t] << endl;
        for(j=0; j<=n; j++)
        {
            graph[j].clear();
            cost[j].clear();
        }
    }
    return 0;
}
