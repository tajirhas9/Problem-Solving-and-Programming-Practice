#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[100];
	int n,i,c=0;
	scanf("%d %s",&n,s);
	for(i=0;i<n;i++)
	{
		if(s[i]=='0' && s[i+1]=='0')
		{
			c*=100;
			i++;
		}
		else if(s[i]== '0')
		{
			c*=10;
		}
		else
			c++;
	}
	cout << c <<  endl;
	return 0;
}
