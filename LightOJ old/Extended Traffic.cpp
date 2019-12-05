#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000000
#define input(n) scanf("%d",&n)

void reset(void);
void queryReset(void);

vector <int> graph[300];
queue <int> q;

int n=299,m,trackCost[300],s,d,cost[300];

int main()
{
	//freopen("Extended Traffic.txt","r",stdin);

	int i,j,k,l,x,y,t,queries,top;

	input(t);

	for(i=1;i<=t;i++)
	{
		reset();
		printf("Case %d:\n",i);
		input(n);
		for(j=1;j<=n;j++)
		{
			input(trackCost[j]); 
		}
		input(m);
		for(j=0;j<m;j++)
		{
			input(x);
			input(y);
			graph[x].push_back(y);
		}
		queryReset();
		for(k=0;k<m;k++)
		{
			top = q.front();
			q.pop();
			for(l=0;l<graph[top].size();l++)
			{
				if(cost[graph[top][l]] > cost[top]+
					(trackCost[graph[top][l]]-trackCost[top])*(trackCost[graph[top][l]]-trackCost[top])*(trackCost[graph[top][l]]-trackCost[top]))
				{
					cost[graph[top][l]] = cost[top]+
						(trackCost[graph[top][l]]-trackCost[top])*(trackCost[graph[top][l]]-trackCost[top])*(trackCost[graph[top][l]]-trackCost[top]);
					q.push(graph[top][l]);
					//cout << "d = " << graph[top][l] << " s = " << top << " and cost = " << cost[graph[top][l]] << endl;
				}
			}
		}
		input(queries);
		for(j=0;j<queries;j++)
		{
			input(d);
			if(cost[d]>=3)	printf("%d\n",cost[d]);
			else
			{
				printf("?\n");
			}
			
		}
	}
	return 0;
}
void reset(void)
{
	for(int i=0;i<n;i++)
	{
		graph[i].clear();
	}
}
void queryReset(void)
{
	while(!q.empty())	q.pop();
	s = 1;
	q.push(s);
	for(int i=0;i<=n;i++)
	{
		cost[i] = MAX;
	}
	cost[s] = 0;
}
