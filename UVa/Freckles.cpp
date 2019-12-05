#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
typedef pair<double,double> pii;
pii points[200],par[200];
int nodes;
struct line
{
	double w;
	pii x,y;
	bool operator < (const line& p) const
	{
		return w < p.w;
	}
};
vector <line> graph;
void reset()
{
	int i;
	for(i=0;i<=nodes;i++)	par[i] = points[i];
}
pii find(pii r)
{
	int i;
	for(i=0;i<nodes;i++)
	{
		if(points[i] == r)		break;
	}
	if(par[i] == points[i])		return par[i];
	return find(par[i]);
} 
double mst(int n)
{
	int i,j;
	pii u,v;
	double c=0;
	sort(graph.begin(),graph.end());
	for(i=0;i<n;i++)
	{
		u = find(graph[i].x);
		v = find(graph[i].y);
		if(u != v)
		{
			for(j=0;j<nodes;j++)
			{
				if(points[j] == u)		break;
			}
			par[j] = v;
			c += graph[i].w;
		}
	}
	return c;
}
void connect(int n)
{
	int i,j,k=0;
	double l;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			graph[k].x = points[i];
			graph[k].y = points[j];
			//cout << graph[k].x.first << "," << graph[k].x.second << endl;
			l = (points[i].first-points[j].first);
			l *= l;
			l += (points[i].second-points[j].second)*(points[i].second-points[j].second);
			l = sqrt(l);
			graph[k].w = l;
			k++;
			if(k==n)	goto check;
		}
	}
	check:
	;
}
int main()
{
	freopen("Freckles.txt","r",stdin);
	int testCase,i;
	cin >> testCase;
	while(testCase--)
	{
		reset();
		cin >> nodes;
		for(i=0;i<nodes;i++)
		{
			cin >> points[i].first >> points[i].second;
		}
		connect(nodes);
	}
	cout << mst(nodes) << endl;
	return 0;
}
