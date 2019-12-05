#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 300000
#define ll long long
long long int find(long long int r);
long long int mst(long long int n,ll int m);
void reset();
struct roads
{
	long long int u,v,w;
	bool operator < (const roads& p) const
	{
		return w < p.w;
	}
};
roads it;
vector<roads> graph;
long long int par[300000];
long long int i,j,k,x,y,z,n,m,cost=0,c=0,actual_cost=0;
int main()
{
	//freopen("Dark Roads.txt","r",stdin);
	while(1)
	{
		reset();
		cin >> n >> m;
		if(n== 0 && m==0)	return 0;
		for(i=;i<=m;i++)
		{
			cin >> x >> y >> z;
			it.u = x;
			it.v = y;
			it.w = z;
			graph.push_back(it);
			actual_cost += z;
		}
		cout << mst(n,m) << endl;
	}
	return 0;
}
ll int find(ll int r)
{
	
	if(par[r] == r)
		return r;
	return find(par[r]);
}
ll int mst(ll int n,ll int m)
{
	sort(graph.begin(),graph.end());
	for(i=0;i<=n;i++)	par[i] = i;
	for(i=0;i<m;i++)
	{
		x = find(graph[i].u);
		y = find(graph[i].v);
		if(x != y)
		{
			par[x] = y;
			c++;
			cost += graph[i].w;
			if(c == m-1)	break;
		}
	}
	return (actual_cost-cost);
}
void reset()
{
	graph.clear();
	actual_cost = 0;
	cost = 0;
	c = 0;
}
