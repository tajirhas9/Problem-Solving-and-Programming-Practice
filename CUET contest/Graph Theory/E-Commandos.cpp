#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define BLACK 1
#define WHITE 0
#define GREY 2
#define cin1(x) 	scanf("%d",&x)
#define cin2(x,y)	scanf("%d %d",&x,&y)
void dfs(int r);
vector <int> graph[200];
int n=0,m,s,d,color[200],c=0,tme=0,du[200],f[200],x=1,countingNodes,visited[200],ma=0;
int main()
{
	int t,i;
	cin1(t);
	for(i=1;i<=t;i++)
	{
		memset(color,WHITE,sizeof(color));
		tme=0;
		c=0;
		countingNodes=0;
		for(int j=0;j<=n;j++)
			graph[j].clear();
		cin2(n,m);
		for(int j=0;j<m;j++)
		{
			int x,y;
			cin2(x,y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		cin2(s,d);
		dfs(s);
		cout << "Case " << i << ": " << f[d] << endl;
	}
	return 0;
}
void dfs(int r)
{
	int top;
	top = r;
	color[top] = GREY;
	du[top] = tme;
	ma = max(ma,du[top]);
	cout << "du[" << top << "] : " << du[top] << endl;
	for(int i=0;i<graph[top].size();i++)
	{
		if(color[graph[top][i]] == WHITE)
		{
			if(graph[top][i] == d && i != (graph[top].size()-1))
			{
				//cout << graph[top][i] << " ";
				swap(graph[top][i],graph[top][(graph[top].size()-1)]);
				//cout << graph[top][i] << endl;
			}
			if(color[graph[top][i]] == WHITE)
			{
				tme++;
				dfs(graph[top][i]);
			}
		}
	}
	color[top] = BLACK;
	f[top] = tme;
	x++;
	tme++;
	cout << "f[" << top << "] : " << f[top] << endl;
}
/*
 *
 2
 7 7
 0 1
 1 2
 2 3
 2 4
 3 5
 5 6
 4 6 
*/
