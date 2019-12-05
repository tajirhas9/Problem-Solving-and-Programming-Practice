#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 10000000
struct maze
{
		pair <int,int> node;
		int cost;
		bool operator < (const maze& p) const
		{
				return cost > p.cost;
		}
};
priority_queue <maze> q;
int t,n,m,i,j,graph[1000][1000],d[1000][1000];
int fx[] = {0,0,-1,1};
int fy[] = {1,-1,0,0};
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				cin >> graph[i][j];
				d[i][j] = MAX;
			}
		}
	}
	maze u,v;
	u.node = (0,0);
	u.cost = graph[0][0];
	d[u.node] = graph[0][0];
	q.push(u);
	while(!q.empty())
	{
		u = q.top();
		u.cost = d[u.node];
		q.pop();
		for(k=0;k<4;k++)
		{
			v.node = graph[i+fx[k]][j+fy[k]];
		}
	}
	return 0;
}
