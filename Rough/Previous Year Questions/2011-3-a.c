#include <stdio.h>
#include <math.h>
int main()
{
	int binary,d=0,r,i,j,p=1;
	scanf("%d",&binary);
	i=0;
	while(binary>0)
	{
		r = binary%10;
		d += r*pow(2,i);
		binary /= 10;
		i++;
	}
	printf("%d\n",d);
	return 0;
}
