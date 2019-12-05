#include <stdio.h>
int main()
{
	int temp,a,b,*p1,*p2;
	scanf("%d %d",&a,&b);
	p1 = &a;
	p2 = &b;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	printf("%d %d\n",a,b);
	return 0;
}
