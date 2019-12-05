#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define cin(n) 	scanf("%d",&n)
#define cout(n)	printf("%d\n",n)
#define MAX 100000
struct edge
{
	int u,v,w;
	bool operator < (const edge& p) const
	{
		return w < p.w;
	}
};
vector<edge> graph;
int findPar(int r);
void reset(void);
void findCostWithBFS(void);
int par[1000],n,m,graph2[1000][1000],s,cost[1000];
int main()
{
//	freopen("Country Roads.txt","r",stdin);
	int t,i,j,x,y,z;
	edge it;
	cin(t);
	for(i=1;i<=t;i++)
	{
		printf("Case %d:\n",i);
		cin(n);
		cin(m);
		reset();
		for(j=0;j<m;j++)
		{
			cin(x);
			cin(y);
			cin(z);
			if(x>y)
			{
				it.u = y;
				it.v = x;
			}
			else
			{
				it.u = x;
				it.v = y;
			}
			it.w = z;
			graph.push_back(edge());
			graph.push_back(it);
		}
		cin(s);
		for(j=0;j<graph.size();j++)
		{
			if(graph[j].u == s)
			{
				swap(graph[j].v,graph[j].u);
			}
		}
		sort(graph.begin(),graph.end());
		for(j=0;j<graph.size();j++)
		{
			x = findPar(graph[j].u);
			y = findPar(graph[j].v);
			if(x!=y)
			{
				par[y] = x;
				graph2[x][y] = graph[j].w;
				graph2[y][x] = graph[j].w;
			}
		}
		findCostWithBFS();
		for(j=0;j<n;j++)
		{
			if(cost[j] == -1000)
				printf("Impossible\n");
			else
				cout(cost[j]);
		}
	}
	return 0;
}
int findPar(int r)
{
	if(par[r] == r)	return r;
	return findPar(par[r]);
}
void reset(void)
{
	for(int i=0;i<=n;i++)
	{
		par[i] = i;
		cost[i] = -1000;
		for(int j=0;j<n;j++)
		{
			graph2[i][j] = MAX;
		}
	}
	graph.clear();
}
void findCostWithBFS(void)
{
	queue <int> q;
	int top;
	q.push(s);
	cost[s] = 0;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(graph2[top][i] == MAX)	continue;
			if(graph2[top][i] > cost[i] && cost[i] == -1000)
			{
				cost[i] = max(graph2[top][i],cost[top]);
				q.push(i);
			}
		}
	}
}
