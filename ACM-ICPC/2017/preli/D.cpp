#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
struct roads
{
	long long u,v,w;
	bool operator < (const roads& p) const
	{
		return w < p.w;
	}
};
vector <roads> graph,graph2;
long long n=50000,m,queries,graph2count=0,q,par[50000],c=0,parX,parY;
void reset(void);
void queryReset(void);
long long find(long long r);
int main()
{
	freopen("D.txt","r",stdin);
	long long testCase,i,j,k,x,y,z;
	scanf("%llu",&testCase);
	for(i=1;i<=testCase;i++)
	{
		reset();
		scanf("%llu %llu",&n,&m);
		for(j=0;j<m;j++)
		{
			scanf("%llu %llu %llu",&x,&y,&z);
			graph.push_back(roads());
			graph[j].u = x;
			graph[j].v = y;
			graph[j].w = z;
		}
		scanf("%llu", &queries);
		for(j=0;j<queries;j++)
		{
			scanf("%llu",&q);
			queryReset();
			for(k=0;k<graph.size();k++)
			{
				if(graph[k].w >= q)
				{
					graph2.push_back(roads());
					graph2[graph2count] = graph[k];
					cout << graph2[graph2count].u << " " << graph2[graph2count].v << " " << graph2[graph2count].w << endl;
					graph2count++;
				}
			}
			for(k=0;k<graph2.size();k++)
			{
				parX = find(graph2[k].u);
				parY = find(graph2[k].v);
				if(parX != parY)
				{
					if(graph2[k].u <= graph2[k].v)
					{
						par[parY] = parX;
					}
					else
					{
						par[parX] = parY;
					}
				}
			}
			for(k=1;k<=n;k++)
			{
				if(par[k] == 1 && k != 1)	
				{
					//cout << k << " " ;
					c++;
				}
			}
			if(j==0)	printf("Case %llu:\n",i);
			printf("%llu\n",c);
		}
	}
	return 0;
}
void reset(void)
{
	c=0;
	graph2count = 0;
	graph.clear();
	graph2.clear();
	
	for(long long p = 0;p <= n;p++)
	{
		par[p] = p;
	}
}
void queryReset()
{
	graph2.clear();
	graph2count = 0;
	c=0;
	
	for(long long p = 0;p <= n;p++)
		par[p] = p;
}
long long find(long long r)
{
	if(par[r] == r)	return r;
	
	par[r] = find(par[r]);
	return par[r];
}
