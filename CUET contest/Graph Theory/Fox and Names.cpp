#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
int n,par[30];
vector<char> graph[30];
string names[200];
int main()
{
	bool flag=false;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> names[i];
		if(!flag)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(names[i][0] == names[j][0] && j < i-1)
				{
					flag = true;
					break;
				}
			}
		}
	}
	if(flag)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	for(char i='a';i<'z';i++)
	{
		graph[i].push_back(i+1);
	}
	for(int i=0;i<n;i++)
	{
		if()
	}
	return 0;
}
