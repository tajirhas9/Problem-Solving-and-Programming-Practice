#include <stdio.h>
void func(int a[])
{
int i = 5,sum=0;
while(i>2)
{
sum += a[--i];
}
printf("%d\n",sum);
}
int main()
{
int a[5] = {5,10,15,20,25};
func(a);
return 0;
}
