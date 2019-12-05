#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define cin1(x)	scanf("%d",&x)
#define cin2(x,y)	scanf("%d %d",&x,&y)
#define cin3(x,y,z)	scanf("%d %d %d",&x,&y,&z)
int n,m,k,source[1005];
bool level[1005];
vector<int> graph[1005];
int vis[1005];
int main()
{
	int T;
	cin1(T);
	for(int i=1;i<=T;i++)
	{
		memset(vis,0,sizeof(vis));
		int pos=0;
		queue<int> q;
		cin3(k,n,m);
		for(int i=0;i<k;i++)
		{
			int x;
			cin1(x);
			source[i] = x;
		}
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin2(x,y);
			graph[x].push_back(y);
		}
		for(int i=0;i<k;i++)
		{
			int top;
			top = source[i];
			q.push(top);
			memset(level,false,sizeof(level));
			level[top] = true;
			while(!q.empty())
			{
				int top;
				top = q.front();
				q.pop();
				vis[top]++;
				for(int i=0;i<graph[top].size();i++)
				{
					int v;
					v = graph[top][i];
					if(!level[v])
					{
						level[v] = true;
						q.push(v);
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(vis[i] == k)
			{
				pos++;
			}
		}
		printf("Case %d: %d\n",i,pos);
		for(int i=0;i<=n;i++)
		{
			graph[i].clear();
		}
	}
	return 0;
}
