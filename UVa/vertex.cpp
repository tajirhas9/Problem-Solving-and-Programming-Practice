#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define GREY 2
#define BLACK 1
#define WHITE 0
vector<int> graph[200];
queue<int> q;
int n=200,queries,color[200];
void reset(void);
void queryReset(void);
void dfs(int s);
int cWhite(void);
int main()
{
	int x,y,countWhite,s;
	while(1)
	{
		reset();
		cin >> n;
		if(n==0)	return 0;
		while(1)
		{
			cin >> x;
			if(x==0)	break;
			while(1)
			{
				cin >> y;
				if(y==0)	break;
				graph[x].push_back(y);
			}
		}
		cin >> queries;
		while(queries--)
		{
			queryReset();
			cin >> s;
			dfs(s);
			countWhite = cWhite();
			cout << countWhite << " ";
			for(int i=1;i<=n;i++)
			{
				if(color[i] != BLACK)
					cout << i << " ";
			}
			cout << endl;
		}
	}
}
void reset(void)
{
	for(int i=0;i<=100;i++)
	{
		graph[i].clear();
		color[i] = WHITE;
	}
}
void queryReset(void)
{
	for(int i=0;i<=n;i++)
	{
		color[i] = WHITE;
	}
}
void dfs(int s)
{
	color[s] = GREY;
	for(int i=0;i<graph[s].size();i++)
	{
		if(graph[s][i] == s)
		{
			color[s] = BLACK;
		}
		else if(color[graph[s][i]] == WHITE)	
		{
			dfs(graph[s][i]);
			color[graph[s][i]] = BLACK;
		}
	}
	return;
}
int cWhite(void)
{
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(color[i] != BLACK)	c++;
	}
	return c;
}
