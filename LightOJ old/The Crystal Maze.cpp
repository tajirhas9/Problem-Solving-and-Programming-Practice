#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define MAX 10000
#define WHITE	0
#define BLACK	1
#define GREY	2
#define cin1(x)		scanf("%d",&x)
#define cin2(x,y)	scanf("%d %d",&x,&y)
#define cin3(x,y,z)	scanf("%d %d %d",&x,&y,&z)
#define pii 		pair<int,int>
void dfs(pii s);
char graph[600][600];
int n,m,k,crystal=0;
int fx[] = {0,0,1,-1};
int fy[] = {-1,1,0,0};
int color[600][600],store[30000];
int main()
{
	int T;
	cin1(T);
	for(int i=1;i<=T;i++)
	{
		cin3(n,m,k);
		getchar();
		for(int j=0;j<n;j++)
		{
			char s[600];
			scanf("%s",s);
			for(int l=0;l<m;l++)
			{
				graph[j][l] = s[l];
			}
		}
		int x;
		for(int j=0;j<k;j++)
		{
			int y,z;
			memset(color,WHITE,sizeof(color));
			cin2(y,z);
			crystal=0;
			dfs(make_pair((y-1),(z-1)));
			store[x++] = crystal;
		}
		printf("Case %d:\n",i);
		for(int j=0;j<x;j++)	printf("%d\n",store[j]);
	}
	return 0;
}
void dfs(pii s)
{
	color[s.first][s.second] = GREY;
	cout << "s " << s.first << " " << s.second << endl;
	for(int i=0;i<4;i++)
	{
		int x,y;
		x = s.first+fx[i];
		y = s.second+fy[i];
		if(x>=0 && x<m && y>=0 && y<n && color[x][y] == WHITE && graph[x][y] != '#')
		{
			cout << "entered " << x << " " << y << endl;
			if(graph[x][y] == 'C')	crystal++;
			dfs(make_pair(x,y));
		}
	}
	color[s.first][s.second] = BLACK;
}
