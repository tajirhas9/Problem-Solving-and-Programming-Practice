#include <stdio.h>
int fib(int f1,int f2,int count)
{
	if(count==0)
		return 0;
	printf("%d ",f1);
	fib(f2,f1+f2,--count);
}
int main()
{
	int count;
	scanf("%d",&count);
	printf("%d ",1);
	fib(1,2,--count);
	return 0;
}
