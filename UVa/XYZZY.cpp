#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define MAX 1000000
void reset(void);
int bellman(void);
struct edges
{
	int u,v;
};
vector <edges> graph;
int n=199,cost[200],flag=0,trackCost[200];
int main()
{
	//freopen("XYZZY.txt","r",stdin);
	int i,j,k,m,x=0;
	while(1)
	{
		x=0;
		reset();
		scanf("%d",&n);
		if(n==-1)	return 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&j);
				graph.push_back(edges());
				graph[x].u = i;
				graph[x].v = j;
				trackCost[i] = k;
				x++;
			}
		}
		flag = bellman();
		//cout << cost[n] << endl;
		if(cost[n] > 0)	printf("winnable\n");
		else 	printf("hopeless\n");
		
	}
}
void reset(void)
{
	int i;
	flag = 0;
	for(i=0;i<=n;i++)
	{
		cost[i] = -1000000;
		trackCost[i] = 0;
	}
	graph.clear();
}
int bellman(void)
{
	int i,j;
	cost[1] = 100;
	for(i=0;i<(n-1);i++)
	{
		for(j=0;j<graph.size();j++)
		{
			if(cost[graph[j].v] < cost[graph[j].u]+trackCost[graph[j].v])
			{
				cost[graph[j].v] = cost[graph[j].u]+trackCost[graph[j].v];
				cout << cost[graph[j].v] << endl;
			}
		}
	}
	for(i=0;i<graph.size();i++)
	{
		if(cost[graph[i].v] > cost[graph[i].u]+trackCost[graph[i].v])
			return 1;
	}
	return 0;
}
