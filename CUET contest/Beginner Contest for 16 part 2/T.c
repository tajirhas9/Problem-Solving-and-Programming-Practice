#include <stdio.h>
int main()
{
    int n,t,k,i;
    scanf("%d %d",&n,&k);
    i = 1;
    while(1)
    {
        t = n*i;
        if((t%10 == k) || (t%10 == 0))
        {
            break;
        }
        i++;
    }
    printf("%d",i);
    return 0;
}
