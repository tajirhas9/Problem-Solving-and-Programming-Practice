#include <stdio.h>
int main()
{
    int n,k,w,sum=0,i;
    scanf("%d %d %d",&k,&n,&w);
    for(i=1;i<=w;i++)
    {
        sum += i*k;
    }
    (sum-n)>=0?printf("%d",sum-n):printf("%d",0);
    return 0;
}
