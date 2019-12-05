#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 2000000
#define ll long long
#define pb push_back
#define WHITE 1
#define BLACK 0
#define GREY 2
void dfs(int r,int cat);
ll int cats[100005],n,m,tc[100005],leaf[100005],z=0,c=0,color[100005];
vector<ll int> graph[100005];
queue <ll int> q;
int main()
{
	memset(tc,-1,sizeof(tc));
	cin >> n >> m;
	for(ll int i=1;i<=n;i++)	cin >> cats[i];
	for(ll int i=1;i<n;i++)
	{
		ll int x,y;
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	for(int i=0;i<=n;i++)	color[i]=WHITE;
	dfs(1,cats[1]);
	cout << c << endl;
	return 0;
}
void dfs(int r,int cat)
{
	tc[r] = cat;
	color[r] = GREY;
	for(int i=0;i<graph[r].size();i++)
	{
		ll int x;
		x = graph[r][i];
		//cout << x << " " << color[x] <<  endl;
		if(color[x] == WHITE)
		{
			//cout << x << " entered " << endl;
			if((cats[x]+tc[r])>m)
			{
				//cout << x << " breaks this path" << endl;
				continue;
			}
			if(cats[x] == 0)
			{
				dfs(x,cats[x]);
				if(graph[x].size()==1 && graph[x][0] == r)	c++;
			}
			else
			{
				dfs(x,tc[r]+cats[x]);
				if(graph[x].size()==1 && graph[x][0] == r)	c++;
			}
		}
	}
	color[r] = BLACK;
}
