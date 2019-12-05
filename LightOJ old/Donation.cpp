#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define cin(n) scanf("%d",&n)
#define cout(i,n) printf("Case %d: %d\n",i,n)
struct edge
{
	int u,v,w;
	bool operator < (const edge& p) const
	{
		return w < p.w;
	}
};
int mst(void);
int find(int r);
bool disconnected(void);
void reset(void);
vector <edge> graph;
int par[100],n,total=0;
int main()
{
	freopen("Donation.txt","r",stdin);
	int t,i,x,y,z,m;
	edge g;
	cin(t);
	for(i=1;i<=t;i++)
	{
		cin(n);
		reset();
		for(x=1;x<=n;x++)
		{
			for(y=1;y<=n;y++)
			{
				cin(z);
				if(z == 0)	continue;
				total += z;
				if(x==y)	continue;
				g.u = x;
				g.v = y;
				g.w = z;
				graph.push_back(g);
			}
		}
		m = mst();
		if(!disconnected())
			cout(i,total-m);
		else
			cout(i,-1);
	}
	return 0;
}
void reset(void)
{
	graph.clear();
	total = 0;
	for(int i=0;i<=n;i++)
	{
		par[i] = i;
	}
}
bool disconnected(void)
{
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(par[i]==i)	c++;
	}
	if(c>1)	return true;
	return false;
}
int find(int r)
{
	if(par[r]==r)	return r;
	return find(par[r]);
}
int mst(void)
{
	int s=0,c=0;
	sort(graph.begin(),graph.end());
	for(int i=0;i<graph.size();i++)
	{
		int a,b;
		a = find(graph[i].u);
		b = find(graph[i].v);
		if(a != b)
		{
			c++;
			par[b] = a;
			s += graph[i].w;
		}
	}
	return s;
}
