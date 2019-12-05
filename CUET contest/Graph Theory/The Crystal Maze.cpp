#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define cin1(x)	scanf("%d",&x)
#define cin2(x,y)	scanf("%d %d",&x,&y)
#define cin3(x,y,z)	scanf("%d %d %d",&x,&y,&z)
#define pii pair<int,int>
#define WHITE 0
#define BLACK 1
#define GREY 2
#define MAX 10000	
void dfs(pii s);
char graph[600][600];
int store[600],n,m,k,crystal=0,color[600][600],level[600][600];
int fx[] = {0,0,1,-1};
int fy[] = {-1,1,0,0};
int main()
{
	int T;
	cin1(T);
	for(int i=1;i<=T;i++)
	{
		cin3(m,n,k);
		getchar();
		for(int j=0;j<m;j++)
		{
			char s[600];
			scanf("%s",s);
			for(int l=0;l<n;l++)
			{
				graph[j][l] = s[l];
				level[j][l] = -1;
			}
		}
		int x=0,y,z;
		printf("Case %d:\n",i);
		for(int j=0;j<k;j++)
		{
			cin2(y,z);
			crystal=0;
			//memset(color,WHITE,sizeof(color));
			dfs(make_pair(y-1,z-1));
			printf("%d\n",crystal);
		}
	}
	return 0;
}
void dfs(pii s)
{
	queue<pii>q;
	q.push(s);
	level[s.first][s.second] = 0;
	if(graph[s.first][s.second] == 'C')	crystal++;
	while(!q.empty())
	{
		pii top;
		top = q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int x,y;
			x = top.first+fx[i];
			y = top.second+fy[i];
			if(x>=0 && x<n && y>=0 && y<m && level[x][y] == -1 && graph[x][y] != '#')
			{
				level[x][y] = 1;
				if(graph[x][y] == 'C')	crystal++;
				q.push(make_pair(x,y));
			}
		}
	}
	/*color[s.first][s.second] = GREY;
	for(int i=0;i<4;i++)
	{
		int x,y;
		x = s.first+fx[i];
		y = s.second+fy[i];
		if(x>=0 && x<n && y>=0 && y<m && color[x][y] == WHITE && graph[x][y] != '#')
		{
			if(graph[x][y] == 'C')	crystal++;
			dfs(make_pair(x,y));
		}
	}
	color[s.first][s.second] = BLACK;*/
}
