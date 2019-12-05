#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100000
vector <int> graph[2000],cost[2000];
queue <int> q;
int s,t,ucost,vcost,v,c=0,i,j,x,y,z,n,m,d[2000];
int main()
{
while(1)
{
for(j=0;j<2000;j++)
d[j] = MAX;
cin >> n >> m;
if(n==0 && m == 0) return 0;
for(i=1;i<=m;i++)
{
cin >> x >> y >> z;
graph[x].push_back(y);
graph[y].push_back(x);
cost[x][y] = z;
cost[y][x] = z;
if(i==1)
{
s = x;
d[s] = 0;
q.push(s);
}
}
while(!q.empty())
{
t = q.front();
q.pop();
ucost = d[t];

for(j=0;j<graph[t].size();j++)
{
v = graph[t][j];
vcost = cost[t][j]+ucost;
if(d[v] > vcost)
{
d[v] = vcost;
q.push(v);
}
}
}
for(j=0;j<n;j++)
{
if(d[j] == MAX) continue;
c += d[j];
}
cout << c << endl;
}
return 0;
}
