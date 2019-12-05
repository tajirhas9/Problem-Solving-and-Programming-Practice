#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
char s[1001][101];
int n,i,j;
int main()
{
	
	bool checked=false;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
		if(!checked)
		{
			if(s[i][0] == 'O' && s[i][1] == 'O')
			{
				s[i][0] = '+';
				s[i][1] = '+';
				checked=true;
			}
			else if(s[i][3] == 'O' && s[i][4] == 'O')
			{
				s[i][3] = '+';
				s[i][4] = '+';
				checked=true;
			}
		}
	}
	if(checked)
	{
		cout << "YES" << endl;
		for(i=1;i<=n;i++)
			printf("%s\n",s[i]);
	}
	else
		cout << "NO" << endl;
	return 0;
}
