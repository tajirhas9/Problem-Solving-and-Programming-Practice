#include <stdio.h>
int main()
{
int sum=0,i=0;
int a[6] = {4,2,6,0,5,10};
while(a[i])
{
sum += a[i];
i++;
}
printf("%d\n",sum);
return 0;
}
