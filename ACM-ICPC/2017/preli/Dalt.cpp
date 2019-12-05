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
long long findFirst(long long r);
long long findSecond(long long r);
int main()
{
	freopen("D.txt","r",stdin);
	long long testCase,i,j,k,l,x,y,z;
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
			c=0;
			scanf("%llu",&q);
			
			for(long long p = 0;p <= n;p++)
			{
				par[p] = p;
			}
			for(k=0;k<graph.size();k++)
			{
				if(graph[k].u <= graph[k].v)
					par[graph[k].v] = graph[k].u;
				else
					par[graph[k].u] = graph[k].v;
			}
			for(k=1;k<=n;k++)	cout << par[k] << " ";
			cout << endl;
			for(k=0;k<graph.size();k++)
			{
				if(graph[k].w < q)
				{
					if(graph[k].v > graph[k].u)
					{
						par[graph[k].v] = graph[k].v;
						for(l=0;l<graph.size();l++)
						{
							if(par[graph[l].u] == graph[k].v || par[graph[l].v] == graph[k].v)	continue;
							
								parX = findSecond(graph[l].u);
								parY = findSecond(graph[l].v);
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
					}
					else
					{
						par[graph[k].u] = graph[k].u;
						for(l=0;l<graph.size();l++)
						{
							if(par[graph[l].u] == graph[k].v || par[graph[l].v] == graph[k].v)	continue;
							
								parX = findSecond(graph[l].u);
								parY = findSecond(graph[l].v);
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
					}
					
				}
				else
				{
					for(l=0;l<graph.size();l++)
					{
						if(par[graph[l].u] == graph[k].v || par[graph[l].v] == graph[k].v)	continue;				
						parX = findSecond(graph[l].u);
						parY = findSecond(graph[l].v);
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
				}
			}
			for(k=1;k<=n;k++)	cout << par[k] << " ";
			for(k=1;k<=n;k++)
			{
				if(par[k] == 1 && k != 1)	c++;
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
}/*
long long findFirst(long long r)
{
	if(par[r] == r)	return r;
	findFirst(par[r]);
}*/
long long findSecond(long long r)
{
	if(par[r] == r)	return r;
	
	par[r] = findSecond(par[r]);
	return par[r];
}

