#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define ii(n) scanf("%d",&n)
#define ic(n) scanf("%c",&n)
#define pii pair<int,int>
#define MAX 1000000

void reset(void);
queue <pii> q;
int grid[100][100],level[100][100];
int fx[4],fy[4];
int n,sx,sy;

int main()
{
	pii source,top;
	char s;
	bool flag = false;
	ii(n);
	getchar();
	ic(s);
	switch(s)
	{
		case 'n':
			fx[0] = 0;
			fy[0] = -1;
			fx[1] = 1;
			fy[1] = 0;
			fx[2] = -1;
			fy[2] = 0;
			fx[3] = 0;
			fy[3] = 1;
			break;
		case 's' :
			fx[0] = 0;
			fy[0] = 1;
			fx[1] = 1;
			fy[1] = 0;
			fx[2] = -1;
			fy[2] = 0;
			fx[3] = 0;
			fy[3] = -1;
			break;
		case 'e':
			fx[0] = 1;
			fy[0] = 0;
			fx[1] = 0;
			fy[1] = 1;
			fx[2] = 0;
			fy[2] = -1;
			fx[3] = -1;
			fy[3] = 0;
			break;
		case 'w':
			fx[0] = -1;
			fy[0] = 0;
			fx[1] = 0;
			fy[1] = 1;
			fx[2] = 0;
			fy[2] = -1;
			fx[3] = 1;
			fy[3] = 0;
			break;
	}
	reset();
	ii(sy);
	ii(sx);
	source.first = sx;
	source.second = sy;
	q.push(source);
	level[sx][sy] = 1;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		flag = false;
		for(int i= 0;i<4;i++)
		{
			int x,y;
			pii next;
			x = top.first+fx[i];
			y = top.second+fy[i];
			if(x>=0 && x <n && y>=0 && y < n && flag == false)
			{
				if(level[x][y] == MAX)
				{
					level[x][y] = level[top.first][top.second]+1;
					next.first = x;
					next.second = y;
					q.push(next);
					flag = true;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",level[j][i]);
		printf("\n");
	}
	return 0;
}
void reset(void)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			level[i][j] = MAX;
		}
	}
}
