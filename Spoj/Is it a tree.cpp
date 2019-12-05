#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define BLACK 1
#define WHITE 0
#define GREY 2
vector<int> graph[20000];
int n,m,flag=0,color[20000],par[20000];
void dfs(int s,int pS);
int main()
{
	int x,y,countPar=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		color[i] = WHITE;
		par[i] = i;
	}
	for(int i=1;i<=m;i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		if(par[y] == y)	par[y] = x;
		else	par[x] = x;
	}
	for(int i=1;i<=n;i++)
	{
		if(par[i] == i)	countPar++;
	}
	if(countPar > 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	dfs(1,1);
	if(flag)	cout << "NO" << endl;
	else 	cout << "YES" << endl;	
	return 0;
}
void dfs(int s,int pS)
{
	color[s] = GREY;
	for(int i=0;i<graph[s].size();i++)
	{
		if(graph[s][i] == pS)	continue;
		if(color[graph[s][i]] == WHITE)
		{
			dfs(graph[s][i],s);
		}
		else if(color[graph[s][i]] == GREY)
			flag = 1;
	}
	color[s] = BLACK;
}
