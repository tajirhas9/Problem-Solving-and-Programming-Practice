#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define pii pair<int,int>
#define MAX 10000000
void reset(void);
queue<pii> q;
int fx[8] = {0,0,1,-1,-1,-1,1,1};
int fy[8] = {1,-1,0,0,1,-1,1,-1};
int grid[350][350],n,m,x,y,w,maxim=0,grid2[350][350];
bool vis[350][350];
int main()
{
	pii point;
	cin >> n >> m;
	reset();
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)	vis[j][k] = false;
		cin >> x >> y >> w;
		grid[x][y] = w;
		maxim = max(maxim,w);
		point.first = x;
		point.second = y;
		q.push(point);
		grid[point.first][point.second] = w;
		grid2[point.first][point.second] = w;
		vis[point.first][point.second] = true;
		while(!q.empty())
		{
			pii top;
			top = q.front();
			q.pop();
			if(grid[top.first][top.second] <= 0)
			{
				while(!q.empty())	q.pop();
				break;
			}
			for(int j=0;j<8;j++)
			{
				pii next;
				next.first = top.first+fx[j];
				next.second = top.second+fy[j];
				if(next.first >=0 && next.first < n && next.second >= 0 && next.second < n)
				{
					if(grid[next.first][next.second] == MAX)
					{
						grid[next.first][next.second] = grid[top.first][top.second]-1;
						grid2[next.first][next.second] = grid[top.first][top.second]-1;
						q.push(next);
						maxim = max(maxim,grid[next.first][next.second]);
						vis[next.first][next.second] = true;
					}
					else if(vis[next.first][next.second] == false)
					{
						int temp;
						temp = grid[next.first][next.second];
						grid[next.first][next.second] = grid[top.first][top.second]-1;
						grid2[next.first][next.second] += grid[top.first][top.second]-1;
						q.push(next);
						maxim = max(maxim,(grid2[next.first][next.second]));
						vis[next.first][next.second] = true;
					}
				}
			}
		}
	}
	cout << maxim << endl;
	return 0;
}
void reset(void)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			grid[i][j] = MAX;
			grid2[i][j] = MAX;
			vis[i][j] = false;
		}
	}
}
