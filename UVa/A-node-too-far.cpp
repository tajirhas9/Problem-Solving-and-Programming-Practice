#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000000
vector <int> graph[MAX];
queue <int> q;
int level[1000000];
int main()
{
    freopen("input.txt","r",stdin);
	int nodes,x,y,i,j,total=0,c=1;
	while(1)
	{
		//for(i=0;i<1000000;i++)
			//level[i] = 0;
		cin >> nodes;
		if(nodes == 0)
			return 0;
		for(i=1;i<=nodes;i++)
		{
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		while(1)
		{
			cin >> x >> y;
			if(x == 0 && y == 0)
				break;
			q.push(x);
			level[x] = 1;
			while(!q.empty())
			{
				for(j=0;j<graph[q.front()].size();j++)
				{
					if(level[graph[q.front()][j]] == 0)
					{
						level[graph[q.front()][j]] = level[q.front()]+1;
						if((level[graph[q.front()][j]]) > y)	total++;
						q.push(graph[q.front()][j]);
					}
				}
				q.pop();
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",c,total,x,y);
			c++;
			total = 0;
			for(i=0;i<1000000;i++)
				level[i]=0;
		}
		for(i=0;i<=1000000;i++)
			graph[i].clear();
	}
}
