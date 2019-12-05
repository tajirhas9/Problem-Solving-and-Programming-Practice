#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAX 10000
struct word
{
	string fromWord,toWord;
	int levelFrom,levelTo;
};
vector<word> graph;
queue <string> q;
string dictionary[210];
int edges;
void makeGraph(int n)
{
	int i,j,k,c=0,m=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i != j && dictionary[i].size() == dictionary[j].size())
			{
				for(k=0;k<dictionary[i].size();k++)
				{
					if(dictionary[i][k] != dictionary[j][k])
						c++;
				}
				if(c==1)
				{
					graph.push_back(word());
					graph[m].fromWord = dictionary[i];
					graph[m].toWord = dictionary[j];
					graph[m].levelFrom = MAX;
					graph[m].levelTo = MAX;
					//cout << graph[m].fromWord << " -> " << graph[m].toWord << endl;
					m++;
				}
				c = 0;
			}
		}
	}
	edges = m;
}
void resetGraph()
{
	int i;
	for(i=0;i<edges;i++)
	{
		graph[i].levelFrom = MAX;
		graph[i].levelTo = MAX;
	}
}
int main()
{
	//freopen("Word Transformation.txt","r",stdin);
	int k,testCase,i,j,z=1;
	size_t pos;
	string x,y,top,line;
	cin >> testCase;
	getchar();
	for(k=1;k<=testCase;k++)
	{
		i=0;
		while(1)
		{
			cin >> x;
			if(x == "*")	break; 
			dictionary[i] = x;
			i++;
		}
		makeGraph(i);
		getline(cin,line);
		z = 1;
		while((getline(cin,line)))
		{
			if(line.length() == 0) break;
			pos = line.find(" ");
			x = line.substr(0,pos);
			y = line.substr(pos+1,line.size());
			resetGraph();
			q.push(x);
			for(i=0;i<edges;i++)
			{
				if(graph[i].fromWord == q.front())
				{
					graph[i].levelFrom = 0;
				}
				else if(graph[i].toWord == q.front())
				{
					graph[i].levelTo = 0;
				}
			}
			while(!q.empty())
			{
				top = q.front();
				q.pop();
				for(i=0;i<edges;i++)
				{
					if(graph[i].fromWord == top && graph[i].levelTo == MAX)
					{
						graph[i].levelTo = graph[i].levelFrom+1;
						q.push(graph[i].toWord);
						//cout << graph[i].toWord << " " << graph[i].levelTo << endl;
						for(j=0;j< edges;j++)
						{
							if(graph[j].fromWord == graph[i].toWord)
							{
								graph[j].levelFrom = graph[i].levelTo;
							}
							else if(graph[j].toWord == graph[i].toWord)
							{
								graph[j].levelTo = graph[i].levelTo;
							}
						}
					}
					else if(graph[i].toWord == top && graph[i].levelFrom == MAX)
					{
						graph[i].levelFrom = graph[i].levelTo+1;
						q.push(graph[i].fromWord);
						//cout << graph[i].fromWord << " " << graph[i].levelFrom << endl;
						for(j=0;j< edges;j++)
						{
							if(graph[j].fromWord == graph[i].fromWord)
							{
								graph[j].levelFrom = graph[i].levelFrom;
							}
							else if(graph[j].toWord == graph[i].fromWord)
							{
								graph[j].levelTo = graph[i].levelFrom;
								
							}
						}
					}
				}
			}
			if(k != 1 && z == 1)	cout << endl;
			cout << x << " " << y << " " ;
			for(i=0;i< edges;i++)
			{
				if(graph[i].fromWord == y)
				{
					cout << graph[i].levelFrom << endl;
					break;
				}
				else if(graph[i].toWord == y)
				{
					cout << graph[i].levelTo << endl;
					break;
				}
			}
			z++;
		}
	}
	return 0;
}
