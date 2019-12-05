#include <stdio.h>
int total = 0;
int fib(int f1,int f2,int count)
{
	if(count==0)
		return 0;
	printf("%d ",f1);
	total += f1;
	fib(f2,f1+f2,--count);
}
int main()
{
	int count;
	scanf("%d",&count);
	printf("%d ",1);
    fib(1,2,--count);
	printf("\nsum = %d\n",total+1);
	return 0;
}
