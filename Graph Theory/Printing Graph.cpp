#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
using namespace std;
#define MAX 10000
vector <int> edges[MAX];
vector <int> cost[MAX];
int main()
{
    int k,nodes,e,i,x,y,c=0;
    cin >> nodes >> e;
    //Input Graph
    for(i=1; i<=e; i++)
    {
        cin >> x >> y;
        edges[x].push_back(y);
    }
    //Out Degree
    cout << "Printing the Outdegrees" << endl;
    for(i=1; i<=nodes; i++)
    {
        if(edges[i].size() == 0)
        {
            continue;
        }
        cout << "Connected with node " << i << " : ";
        for(int j=0; j<edges[i].size(); j++)
        {
            cout << edges[i][j] << " ";
        }
        cout << " (total = " << edges[i].size() << ")" << endl; //Total
    }
    //In Degree
    cout << "Printing Indegrees" << endl;
    for(k=1; k<=nodes; k++)
    {
        cout << "Connected with node " << k << " : ";
        for(i=1; i<=nodes; i++)
        {
            if(edges[i].size() == 0)
            {
                continue;
            }
            for(int j=0; j<edges[i].size(); j++)
            {
                if(edges[i][j] == k)
                {
                    cout << i << " ";
                    c++;
                }
            }
        }
        cout << " (total = " << c << ")" << endl;
        c = 0;

    }
        return 0;
}
