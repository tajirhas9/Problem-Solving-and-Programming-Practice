#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	int a,b,sub,i=0,r;
	char c[20000];
	scanf("%d %d",&a,&b);
	sub = a-b;
			while(sub>0)
	{
		r = sub%10;
		sub /= 10;
		c[i] = r+'0';
		i++;
	}
	c[i] = '\0';
	if(c[0] < (8+'0'))
		c[0] += 1;
	else
		c[0] -= 1;
	while(i--)	printf("%c",c[i]);
	printf("\n");
	return 0;
}
