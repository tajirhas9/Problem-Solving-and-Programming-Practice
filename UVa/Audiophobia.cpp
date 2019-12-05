#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
    int u,v,cost;
    bool operator < (const edge& p) const
    {
        return cost < p.cost;
    }
};
vector <edge> graph;
int costTrack[1000][1000];
int n,m,queries,s,d,par[10000];
void reset()
{
    int i;
    graph.clear();
}
int findPar(int r)
{
    if(par[r] == r)     return r;
    findPar(par[r]);
}
int minCost(int s,int d)
{
    int koto=0;
    while(d != s)
    {
        if(costTrack[d][par[d]] > koto)  koto = costTrack[d][par[d]];
        d = par[d];
    }
}
int main()
{
    int i=0,k,j,x,y,w,c=0;
    while(i++)
    {
        reset();
        cin >> n >> m >> queries;
        if(n==0 && m == 0 && queries == 0)  return 0;
        for(j=0;j<m;j++)
        {
            cin >> x >> y >> w;
            graph.push_back(edge());
            graph[j].u = x;
            graph[j].v = y;
            graph[j].cost = w;
            costTrack[x][y] = w;
            costTrack[y][x] = w;
        }
        for(j=0;j<queries;j++)
        {
            cin >> s >> d;
            sort(graph.begin(),graph.end());
            for(k=0;k<=n;k++)   par[k] = k;
            for(k=0;k<graph.size();k++)
            {
                x = findPar(graph[k].u);
                y = findPar(graph[k].v);
                if(x != y)
                {
                    par[x] = y;
                    cout << "Parent of "<< x << " is " << par[x] << endl;
                    c++;
                    if(c == n-1)    break;
                }
            }
            cout << minCost(s,d) << endl;
        }
    }
}
