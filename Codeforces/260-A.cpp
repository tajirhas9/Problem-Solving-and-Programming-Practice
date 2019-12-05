#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int b,n;
char  a[200010];
int main()
{
	int r=0,l;
	scanf("%s %d %d",a,&b,&n);
	l = strlen(a);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=9;j++)
		{
			a[l] =  j+'0';
			r = 0;
			for(int k=0;k<=l;k++)
			{ 
				r *= 10;
				r += a[k]-'0';
				r %= b;
			}
			if(r==0)	break;
		}
		l++;
	}
	a[l] = '\0';
	if(r==0)
		printf("%s\n",a);
	else
		printf("-1\n");
	
	return 0;
}
