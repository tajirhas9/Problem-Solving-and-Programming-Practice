#include <bits/stdc++.h>
#include <queue>
#include <cstring>
using namespace std;
#define pii pair<int,int>
#define MIN 100000

void reset(void);
void levelReset(void);
void input(int j);
void bfs(pii a);

queue <pii> q;
int fx[4] = {0,0,1,-1};
int fy[4] ={1,-1,0,0};

char graph[30][30];
char s[30];
int level[30][30],n=30,m=30;
bool vis[30][30];
pii posA,posB,posC,posH;

int main()
{
	//freopen("Power Puff Girls.txt","r",stdin);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d %d",&n,&m);
		reset();
		for(int j=0;j<n;j++)	input(j);
		levelReset();
		bfs(posH);
		printf("Case %d: %d\n",i,max(max(level[posA.first][posA.second],level[posB.first][posB.second]),level[posC.first][posC.second]));
	}
	return 0;
}
void reset(void)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			level[i][j] = MIN;
			graph[i][j] = '\0';
			vis[i][j] = false;
		}
	}
}
void levelReset(void)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i == posH.first && j == posH.second)
				continue;
			level[i][j] = MIN;
		}
	}
}
void input(int j)
{
	scanf("%s",s);
	for(int k=0;k<m;k++)
	{
		graph[j][k] = s[k];
		if(graph[j][k] == 'a')
		{
			posA.first = j;
			posA.second = k;
		}
		if(graph[j][k] == 'b')
		{
			posB.first = j;
			posB.second = k;
		}
		if(graph[j][k] == 'c')
		{
			posC.first = j;
			posC.second = k;
		}
		if(graph[j][k] == 'h')
		{
			posH.first = j;
			posH.second = k;
		}
	}
}
void bfs(pii s)
{
	pii top,x;
	bool reached = false;
	q.push(s);
	level[s.first][s.second] = 0;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		if(reached == true)	continue;
		for(int i=0;i<4;i++)
		{
			x.first = top.first+fy[i];
			x.second = top.second+fx[i];
			if(x.first >= 0 && x.first < n && x.second >=0 && x.second < m)
			{
				if(graph[x.first][x.second] != 'm' && graph[x.first][x.second] != '#' && vis[x.first][x.second] == false) 
				{
					level[x.first][x.second] = min(level[x.first][x.second],(level[top.first][top.second]+1));
					vis[x.first][x.second] =  true;
					q.push(x);
				}
			}
		}
	}
}
