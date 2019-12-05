#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define MAX 90005
#define cin3(x,y,z) scanf("%d %d %d",&x,&y,&z)
typedef pair<int,int> ii;
ii dfs(ii s,int cl,int l);
bool vis[305][305]={false};
int fx[] = {0,0,1,-1};
int fy[] = {1,-1,0,0};
int row,col,tubes,tubeL,lastTube;
int main()
{
	ii s;
	s.first = 0;
	s.second=0;
	cin3(row,col,tubes);
	tubeL = (row*col)/tubes;
	lastTube = tubeL+((row*col)%tubes);
	for(int i=1;i<=tubes;i++)
	{
		(i==tubes) ?cout << lastTube << " " : cout << tubeL << " ";
		if(i==tubes)
		{
			s = dfs(s,1,lastTube);
		}
		else
		{
			 s = dfs(s,1,tubeL);
		}
		cout << endl;
	}
	return 0;
}
ii dfs(ii s,int cl,int l)
{
	if(cl>l) 	return s;
	vis[s.first][s.second] = true;
	cout << s.first+1 << " " << s.second+1 << " ";
	for(int i=0;i<4;i++)
	{
		int x,y;
		x = s.first+fx[i];
		y = s.second+fy[i];
		if(x>=0 && x<row && y>=0 && y<col && vis[x][y]==false)
		{
			s = dfs(ii(x,y),++cl,l);
			break;
		}
	}
	return s;
}
