#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define INFINITY 1000000
int cost[1000],graph[1000][1000];
int main()
{
    int root, node;
    int i,e,kase,u,v,w;
    memset(graph,0,sizeof(graph));
    cin >> e;
    for(kase = 1; kase <= e; kase++)
    {
        cin >> u >> v >> w;
        graph[u][v] = w;
        //graph[v][u] = w;
    }
    for(i = 0; i< 1000; i++)
    {
        cost[i] = INFINITY;
    }
    cin >> root; //From
    cin >> node; //To
    queue <int> q;
    q.push(root);
    cost[root] = 0;
    while(!q.empty())
    {
        int top;
        top = q.front();
        for(i = 1; i<= 1000; i++)
        {
            if(graph[top][i] != 0 && cost[i] > (cost[top] + graph[top][i]))
            {
                cost[i] = cost[top] + graph[top][i];	//If cost found from this path is less than cost found in previous path.

                cout<< i << endl;
                q.push(i);
            }
        }
        q.pop();
    }
    cout << cost[node] << endl;
    return 0;
}
