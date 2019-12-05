#include <stdio.h>
int main()
{
	int index=0,i;
	for(i=0;i<10;i++)
	{
		int i = 0;
		while(++i < 5)
		{
			index++;
			printf("%d ",i);
		}
		printf("index=%d\n",index);
	}
	printf("\nindex = %d\n",index);
	return 0;
}
