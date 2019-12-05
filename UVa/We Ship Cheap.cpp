#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
string x,y,s,d,t;
vector <string> graph[100000],parent[100000];
int edge,i,j,level[100000];
queue <string> q;
int main()
{
    while((cin>>edge))
    {
        for(i=0; i<100000; i++)
            level[i] = -1;
        for(i=1; i<=edge; i++)
        {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        cin >> s >> d;
        q.push(s);
        level[s]  = 0;
        while(!q.empty())
        {
            t = q.front();
            q.pop();
            for(i=0;i<graph[t].size();i++)
            {
                if(level[graph[t][i]] == -1)
                {
                    q.push(graph[t][i]);
                    level[graph[t][i]] = level[t]+1;
                }
            }
        }
        cout << level[d] << endl;
    }
    return 0;
}
