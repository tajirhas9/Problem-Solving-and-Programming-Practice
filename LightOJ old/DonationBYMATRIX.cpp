#include <bits/stdc++.h>
using namespace std;
#define cin(n) scanf("%d",&n)
int graph[200][200],n,sum=0;
int main()
{
	freopen("Donation.txt","r",stdin);
	int i,j,t,k;
	cin(t);
	for(i=1;i<=t;i++)
	{
		cin(n);
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				cin(graph[j][k]);
			}
		}
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if(j==k && graph[j][k] > 0)	
				{
					sum += graph[j][k];
					graph[j][k] = 0;
				}
				if(graph[j][k] > 0 && graph[k][j] > 0)
				{
					sum += max(graph[j][k],graph[k][j]);
					graph[j][k] = 0;
					graph[k][j] = 0;
				}
			}
		}
		cout << sum << endl;
		sum=0;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
				graph[j][k] = 0;
		}
	}
	return 0;
}
