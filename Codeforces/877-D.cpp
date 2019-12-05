#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int> 
#define GREY 2
#define WHITE 1
#define BLACK 0
void dfs(pii s);
char graph[1005][1005];
int n,m,k;
int x1,x2,y,y2;
int color[1005][1005],t=0,tme=0;
pii s,d,dir;
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};
int main()
{
	char str[10005];
	cin >> n >> m >> k;
	getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%s",str);
		getchar();
		for(int j=0;j<m;j++)
		{
			graph[i][j] = str[j];
			color[i][j] = WHITE;
		}
	}
	cin >> x1 >> y >> x2 >> y2;
	s.first = x1-1;
	s.second = y-1;
	d.first = x2-1;
	d.second = y2-1;
	dir.first = 0;
	dir.second = 0;
	dfs(s);
	(t>0)?  cout << t << endl : cout << -1 << endl;
	return 0;
}
void dfs(pii r)
{
	color[r.first][r.second] = GREY;
	for(int i=0;i<4;i++)
	{
		pii it;
		it.first = r.first+fx[i];
		it.second = r.second+fy[i];
		int x,y;
		x  = it.first;
		y = it.second;
		if(x>=0 && x <n && y >= 0 && y < m)
		{
			if(graph[it.first][it.second] == '.' && color[x][y] == WHITE)
			{
				if(dir.first == fx[i] && dir.second == fy[i])
				{
					if(tme < k)
					{
						tme++;
						dfs(it);
					}
					else
					{
						t++;
						tme=1;
						dfs(it);
					}
				}
				else
				{
					dir.first = fx[i];
					dir.second = fy[i];
					tme=1;
					t++;
					dfs(it);
				}
			}
		}
	}
	color[r.first][r.second] = BLACK;
}
