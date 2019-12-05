#include <stdio.h>
int main()
{
	int *p,i;
	for(i=0;i<=9;i++)
	{
		p = &i;
		printf("%d ",*p);
	}
	return 0;
}
