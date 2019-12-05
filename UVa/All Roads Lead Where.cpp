#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 10000000
struct r
{
	string from,to;
	int levelFrom,levelTo;
};
vector <r> graph;
queue <string> q;
int roads,queries,i,j;

void print(string y,string x)
{
	int i,k=0;
	string path[100000];
	path[k] = y;
	k++;
	for(i=0;i<roads;i++)
	{
		if(graph[i].to == y && graph[i].levelFrom == (graph[i].levelTo-1))	
		{
			path[k] = graph[i].from;
			y = path[k];
			i = -1;
			k++;
		}
		else if(graph[i].from == y && graph[i].levelTo == (graph[i].levelFrom-1))
		{
			path[k] = graph[i].to;
			y = path[k];
			i = -1;
			k++;	
		}
		if(y == x)	
		{
			break;
		}
	}
	while(k--)
	{
		cout << path[k][0];
		path[k].clear();
	}
	cout << endl;
	
}
void resetGraph()
{
	int i;
	for(i=0;i<roads;i++)
	{
		graph[i].levelFrom = MAX;
		graph[i].levelTo = MAX;
	}
}
int main()
{
	//freopen("All Roads Lead Where.txt","r",stdin);
	int testCases,k;
	string x,y,top;
	cin >> testCases;
	for(j=1;j<=testCases;j++)
	{
		cin >> roads >> queries;
		getchar();
		for(i=0;i<roads;i++)
		{
			cin >> x >> y;
			getchar();
			graph.push_back(r());
			graph[i].from = x;
			graph[i].to = y;
			graph[i].levelFrom = MAX;
			graph[i].levelTo = MAX;
		}
		for(i=1;i<=queries;i++)
		{
			resetGraph();
			cin >> x >> y;
			q.push(x);
			for(k=0;k<roads;k++)
			{
				if(graph[k].from == q.front())
				{
					graph[k].levelFrom = 0;
				}
				else if(graph[k].to == q.front())
				{
					graph[k].levelTo = 0;
				}
			}
			while(!q.empty())
			{
				top = q.front();
				q.pop();
				for(k=0;k<roads;k++)
				{
					if(graph[k].from == top && graph[k].levelTo == MAX)
					{
						graph[k].levelTo = graph[k].levelFrom+1;
						q.push(graph[k].to);
						for(int l = 0;l<roads;l++)
						{
							if(graph[l].from == graph[k].to)
								graph[l].levelFrom = graph[k].levelTo;
							else if(graph[l].to == graph[k].to)
								graph[l].levelTo = graph[k].levelTo;
						}
					}
					else if(graph[k].to == top && graph[k].levelFrom == MAX)
					{
						graph[k].levelFrom = graph[k].levelTo+1;
						q.push(graph[k].from);
						for(int l = 0;l<roads;l++)
						{
							if(graph[l].from == graph[k].from)
								graph[l].levelFrom = graph[k].levelFrom;
							else if(graph[l].to == graph[k].from)
								graph[l].levelTo = graph[k].levelFrom;
						}
					}
				}
			}
			if(i==1 && j != 1)	cout << endl;
			print(y,x);
		} 
	}
	return 0;
}
