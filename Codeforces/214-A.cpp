#include <bits/stdc++.h>
using namespace std;
int main()
{
	int c=0;
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(a=0;a<=max(n,m);a++)
	{
		for(b=0;b<=max(n,m);b++)
		{
			if((a*a)+b == n && a+(b*b) == m)	c++;
		}
	}
	printf("%d\n",c);
	return 0;
}
