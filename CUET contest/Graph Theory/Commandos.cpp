#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define BLACK 1
#define WHITE 0
#define GREY 2
#define TARGET 3
#define cin1(x) 	scanf("%d",&x)
#define cin2(x,y)	scanf("%d %d",&x,&y)
void bfs(int r,int *level);
int bfsReturn(int r);
vector <int> graph[200];
int n=0,m,s,d,color[200],c=0,tme=0,du[200],f[200],ReachTime=0,destroyed=0;
int main()
{
	int t,i;
	int level1[200],level2[200];
	cin1(t);
	for(i=1;i<=t;i++)
	{
		memset(color,WHITE,sizeof(color));
		tme=0;
		c=0;
		ReachTime=0;
		for(int j=0;j<=n;j++)
			graph[j].clear();
		cin2(n,m);
		for(int j=0;j<m;j++)
		{
			int x,y;
			cin2(x,y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		cin2(s,d);
		memset(level1,-1,sizeof(level1));
		memset(level2,-1,sizeof(level2));
		bfs(s,level1);
		bfs(d,level2);
		int m=0;
		for(int i=0;i<n;i++)
		{
			m = max(m,(level1[i]+level2[i]));
		}
		printf("Case %d: %d\n",i,m);
	}
	return 0;
}
void bfs(int r,int *level)
{
	int top;
	queue <int> q;
	memset(level,-1,sizeof(level));
	q.push(r);
	level[r] = 0;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		for(int i=0;i<graph[top].size();i++)
		{
			int v;
			v = graph[top][i];
			if(level[v] == -1)
			{
				level[v] = max(level[v],level[top]+1);
				q.push(v);
			}
		}
	}
}
/*
2
7
8
0 4
0 3
0 2
1 3
1 6
1 5
1 2
5 3
4 3
*/
