#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
int bonds;
int main()
{
	int i,testCases;
	string x,y;
	for(i=1;i<=testCases;i++)
	{
		cin >> bonds;
		for(int j = 1;j<=bonds;j++)
		{
			cin >> x >> y;
			makeFriendship(x,y);
		}
	}
}
