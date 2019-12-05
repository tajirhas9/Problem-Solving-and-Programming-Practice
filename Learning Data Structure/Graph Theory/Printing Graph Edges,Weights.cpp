#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
#define MAX 100000
vector <int> edges[MAX];
vector <int> cost[MAX];
int main()
{
    int n,e,i,x,y,c,s,j,in[MAX],out[MAX],connect=0;
    cin >> n >> e;
    for(i=1;i<=e;i++)
    {
        cin >> x >> y >> c;
        edges[x].push_back(y);
        edges[y].push_back(x);
        cost[x].push_back(c);
    }
    for(j=1;j<=n;j++)
    {
        s = edges[j].size();
        cout << j << " >> ";
        for(i=0;i<s;i++)
        {
            cout << edges[j][i] << " ";
            connect++;
        }
        cout << endl;
        cout << "Total connected node with " << j << " : " << connect << endl;
        connect=0;
    }
    //In Degree
    for(i=1;i<=n;i++)
    {
    }
    return 0;
}
