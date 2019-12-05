#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1000000
struct flight
{
	int plane,cost;
	bool operator < (const flight& p) const
	{
		return cost > p.cost;
	}
};
priority_queue <flight> q;
int graph[1000][1000],day[1000][1000],level[1000],flag = 0;
int minCa = 0,minCd = 0;
int i,j,d,f,t,c,n,m,k;
int main()
{
	freopen("854-D.txt","r",stdin);
	for(i=0;i<100000;i++)
	{
		level[i] = MAX;
		for(j=0;j<10000;j++)
		{
			graph[i][j] = MAX;
			day[i][j] = MAX;
		}
	}
	cin >> n >> m >> k;
	for(i=1;i<=m;i++)
	{
		cin >> d >> f >> t >> c;
		if(graph[f][t] != MAX)
		{
			if(day[f][t] > d || graph[f][t] < c)
			{
				graph[f][t] = c;
				day[f][t] = d;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(graph[0][i] == MAX || graph[i][0] == MAX)
		{
			flag = 1;
			break;
		}
		minCd += graph[0][i];
		minCa += graph[i][0];
	}	
	if(flag == 1)	cout << -1 << endl;
	else
	{
		cout << minCd+minCa << endl;
	}
	
	return 0;
}
