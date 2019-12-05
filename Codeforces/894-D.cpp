#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
vector<ii> graph[1000005];
int n,m,cost[1000005],s,h,hap[1000005];
bool vis[1000005];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		double x;
		scanf("%d",&w);
		u = i+1;
		x = ((double)i+1)/2;
		v = floor(x);
		graph[u].push_back(ii(v,w));
		graph[v].push_back(ii(u,w));
		graph[u].push_back(ii(u,0));
		graph[v].push_back(ii(v,0));
	}
	//cout << "exit" << endl;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d",&s,&h);
		int c=0;
		memset(vis,false,sizeof(vis));
		memset(cost,-1,sizeof(cost));
		memset(hap,0,sizeof(hap));
		queue<int> q;
		q.push(s);
		vis[s] = true;
		c += h;
		//cout << c << endl;
		cost[s] = 0;
		while(!q.empty())
		{
			int top;
			top = q.front();
			q.pop();
			for(int i=0;i<graph[top].size();i++)
			{
				int v,w;
				v = graph[top][i].first;
				w = graph[top][i].second;
				if(!vis[v])
				{
					cost[v] = w+cost[top];
					//cout << "cost of " << v << ": " << h-cost[v] << endl;
					if((h-cost[v])>=0)
					{
						//cout << "added cost " << cost[v] << endl;
						if(hap[v]< (h-cost[v]))
						{
							c -= hap[v];
							hap[v] = h-cost[v];
							c += hap[v];
						}
					}
					vis[v] = true;
					q.push(v);
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}
