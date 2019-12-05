#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define WHITE 0
#define BLACK 2
#define GREY 1
#define cin3(x,y,z)	scanf("%d %d %d",&x,&y,&z)
#define cin1(x)	scanf("%d",&x)
typedef pair<int,int> ii;
void reset(void);
int dfs(int s,vector<ii> graph[]);
int n,inDegree[105],color[105],maxDegreePos=1,cost=0,vis=0;
bool second = false;
int main()
{
	int T;
	
	cin1(T);
	for(int i=1;i<=T;i++)
	{
		cin1(n);
		reset();
		vector <ii> graph[1000];
		for(int i=0;i<n;i++)
		{
			int x,y,z;
			cin3(x,y,z);
			graph[x].push_back(ii(y,z));
			inDegree[y]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(inDegree[i] == 0)	maxDegreePos=i;
		}
		int c1,c2;
		c1 = dfs(maxDegreePos,graph);
		swap(graph[maxDegreePos][0],graph[maxDegreePos][1]);
		memset(color,WHITE,sizeof(color));
		cost=0;
		vis=0;
		second=true;
		c2 = dfs(maxDegreePos,graph);
		printf("Case %d: %d\n",i,min(c1,c2));
	}
	return 0;
}
void reset(void)
{
	memset(inDegree,0,sizeof(inDegree));
	memset(color,WHITE,sizeof(color));
	cost=0;
	vis=0;
}
int dfs(int s,vector<ii> graph[])
{
	bool moved=false;
	color[s] = GREY;
	vis++;
	if(vis==n+1)	return 0;
	for(int i=0;i<graph[s].size();i++)
	{
		int v;
		v = graph[s][i].first;
		if(color[v] == WHITE)
		{
			moved=true;
			dfs(v,graph);
		}
		else if(v==maxDegreePos)	return 0;
	}
	if(!moved)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<graph[i].size();j++)
			{
				int v;
				v = graph[i][j].first;
				if(v == s && (color[i] == WHITE || (i == maxDegreePos && vis==n)))
				{
					cost += graph[i][j].second;
					dfs(i,graph);
				}
				else if(v==maxDegreePos)	return 0;
			}
		}
	}
	return cost;
}
/*
1
6
1 5 4
5 3 8
2 4 15
1 6 16
2 3 23
4 6 42
*/
