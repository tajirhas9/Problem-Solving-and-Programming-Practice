#include <bits/stdc++.h>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define BLACK 1
#define WHITE 0
#define GREY 2
void dfs(ll int s,ll int step);
ll int n,m,d,s[100005],color[100005];
vector<int> graph[100005];
map<int,int> ma;
int main()
{
	ll int i,j,node=0;
	cin >> n >> m >> d;
	for(i=1;i<=m;i++)
	{
		cin >> s[i];
	}
	for(i=1;i<n;i++)
	{
		ll int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(i=1;i<=m;i++)
	{
		memset(color,WHITE,sizeof(color));
		dfs(s[i],0);
	}
	map<int,int> :: iterator it;
	for(it = ma.begin(); it != ma.end();it++)
	{
		if(it->second == m)
		{
			node++;
		}
	}
	cout << node << endl;
	return 0;
}
void dfs(ll int s,ll int step)
{
	if(step > d)	return;
	step++;
	ll int i;
	color[s] = GREY;
	for(i=0;i<graph[s].size();i++)
	{
		if(color[graph[s][i]] == WHITE)
		{
			dfs(graph[s][i],step);
		}
	}
	color[s] = BLACK;
	ma[s]++;
}
