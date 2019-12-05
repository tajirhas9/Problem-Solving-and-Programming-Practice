#include <bits/stdc++.h>
#include <cstring>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define BLACK 1
#define WHITE 0
#define GREY 2
#define BLUE 3
void dfs(pii xy);
queue<pii> q;
int n,m,color[105][105];
int fx[] = {1,0,0,-1};
int fy[] = {0,1,-1,0};
char graph[105][105];
int main()
{
	cin >> n >> m;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
			color[i][j] = WHITE;
	}
	getchar();
	for(int i=0;i<n;i++)
	{
		int j;
		char s[200];
		scanf("%s",s);
		getchar();
		for(j=0;j<strlen(s);j++)
		{
			graph[i][j] = s[j];
		}
	}
	if(n==1 && m==1 && graph[n-1][m-1] == '.')
	{
		cout << "B" << endl;
		return 0;
	}
	dfs(make_pair(0,0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout << graph[i][j];
		cout << endl;
	}
	return 0;
}
void dfs(pii x)
{
	q.push(x);
	color[0][1] = WHITE;
	while(!q.empty())
	{
		pii top;
		top = q.front();
		q.pop();
		if(top.first >= n || top.second >= m || color[top.first][top.second] == BLACK)	continue;
		if(color[top.first][top.second] == BLUE)
		{
			color[top.first][top.second] = WHITE;
			continue;
		}
		color[top.first][top.second] = GREY;
		if(graph[top.first][top.second] == '.')	graph[top.first][top.second] = 'B';
		for(int i=0;i<4;i++)
		{
			pii it;
			it.first = top.first+fx[i];
			it.second = top.second+fy[i];
			if(it.first <n && it.first >=0 && it.second >= 0 && it.second <m && color[it.first][it.second] == WHITE)
			{
				if(graph[top.first][top.second] == 'B' && (color[it.first][it.second] == WHITE || color[it.first][it.second] == BLUE) && graph[it.first][it.second] != '-')
				{
					graph[it.first][it.second] = 'W';
					color[it.first][it.second] = GREY;
				}
				else if(graph[top.first][top.second] == 'W' && (color[it.first][it.second] == WHITE || color[it.first][it.second] == BLUE) && graph[it.first][it.second] != '-')
				{
					graph[it.first][it.second] = 'B';
					color[it.first][it.second] = GREY;
				}
				else if(graph[top.first][top.second] == '-' && (color[it.first][it.second] == WHITE || color[it.first][it.second] == BLUE) && graph[it.first][it.second] != '-')
				{
					graph[it.first][it.second] = 'B';
					color[it.first][it.second] = BLUE;
				}
				q.push(it);
			}
		}
		color[top.first][top.second] = BLACK;
	}
}
