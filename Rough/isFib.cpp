#include <stdio.h>

int main() 
{
	int a[100],i,j,t;

	a[0] = 0;
	a[1] = 1;

	for( i=2; i<=65; ++i )
	{
		a[i] = a[i-1] + a[i-2];
	}

	scanf("%d", &t);

	for(j=1; j<=t ; ++j ) 
	{
		scanf("%d",&i);
		printf("%d\n", a[i]);
	}

	return 0;
}