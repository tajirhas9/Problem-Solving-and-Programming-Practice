#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000000
int bellman(void);
void reset(void);
struct edges
{
	int u,v,w;
};
vector<edges> graph;
int n=1001,m,cost[2000];
int main()
{
	int t,i,x,y,z;
	scanf("%d",&t);
	while(t--)
	{
		reset();
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			graph.push_back(edges());
			graph[i].u = x;
			graph[i].v = y;
			graph[i].w = z;
		}
		if(bellman())	printf("possible\n");
		else 	printf("not possible\n");
	}
	return 0;	
}
int bellman(void)
{
	int i,j;
	cost[graph[0].u] = 0;
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<graph.size();j++)
		{
			if(cost[graph[j].v] > (cost[graph[j].u]+graph[j].w))
			{
				cost[graph[j].v] = cost[graph[j].u]+graph[j].w;
				//cout <<	graph[j].v <<" "  << cost[graph[j].v]<< endl;
			}
		}
	}
	for(j=0;j<graph.size();j++)
	{
		if(cost[graph[j].v] > (cost[graph[j].u]+graph[j].w))
			return 1;
	}
	return 0;
}
void reset(void)
{
	int i;
	for(i=0;i<=1000;i++)
	{
		cost[i] = MAX;
	}
	graph.clear();
}
