#include <stdio.h>
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i%7==0)
            continue;
        else
            sum += i;
    }
    printf("%d",sum);
    return 0;
}
