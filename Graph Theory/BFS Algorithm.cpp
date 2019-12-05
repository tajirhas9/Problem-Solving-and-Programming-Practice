#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10000

int path(int from,int to);

vector <int> edges[MAX];
queue <int> q;
int level[MAX] = {0},parent[1000];

int main()
{
    int from,to,x,y,n,e,i,j;
    cin >> n >> e;
    for(i=1;i<=e;i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    cout << "From? : ";
    cin >> from;
    cout << "Where? : ";
    cin >> to;
    level[from] = 1;
    q.push(from);
    while(!q.empty())
    {
        for(j=0;j<edges[q.front()].size();j++)
        {
            if(level[edges[q.front()][j]] == 0)
            {
                q.push(edges[q.front()][j]);
                level[edges[q.front()][j]] = level[q.front()]+1;
                parent[edges[q.front()][j]] = q.front();
            }
        }
        q.pop();
    }
    path(from,to);
    cout << endl;
    cout << level[to]-1 << endl;
    return 0;
}
int path(int from,int to)
{
    if(to == from)
    {
        cout << from << " ";
        return 0;
    }
    path(from,parent[to]);
    cout << to << " ";
    return 0;
}
