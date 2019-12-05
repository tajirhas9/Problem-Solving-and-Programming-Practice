#include <bits/stdc++.h>
using namespace std;
int n,m,b[105],g[105],c=0,loop=0;
bool g1[105];
int dfs(int boy,int team);
int main()
{
	cin >> n;
	for(int i=0;i<n;i++)	cin >> b[i];
	cin >> m;
	for(int i=0;i<m;i++)
	{	
		cin >> g[i];
		g1[i] =  false;
	}
	sort(b,b+n);
	sort(g,g+m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			if (abs(b[i] - g[j]) <= 1)
			{
				g[j] = 1000;
				c++;
				break;
			}
		}
	}
	cout << c << endl;
}
