#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define cinI(n)		scanf("%d",&n)
#define cinS(s)		scanf("%s",s)
char graph[200][200];
int n,m;
int fx[5] = {0,0,0,1,-1};
int fy[5] = {0,1,-1,0,0};
queue <pair<int,int>> q;
int main()
{
	int i;
	bool black=true,white=false;
	char s[200];
	cinI(n);
	cinI(m);
	getchar();
	for(i=0;i<n;i++)
	{
		if(i != 0)
		{
			if(graph[i-1][0] == 'B')	
			{
				black = false;
				white = true;
			}
			else
			{
				black = true;
				white = false;
			}
		}
		for(int j=0;j<m;j++)
		{
			if(black)
			{
				graph[i][j] = 'B';
				black = false;
				white = true;
			}
			else
			{
				graph[i][j] = 'W';
				white = false;
				black = true;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		int j;
		cinS(s);
		getchar();
		for(j=0;j<strlen(s);j++)
		{
			if(s[j] == '-')	graph[i][j] = s[j];
		}
	}
	for(i=0;i<n;i++)	cout << graph[i] << endl;
	return 0;
}
