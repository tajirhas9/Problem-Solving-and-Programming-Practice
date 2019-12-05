#include <stdio.h>
int main()
{
    int n,a[3],count0=0,count=0,i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        for(i=0;i<3;i++)
        {
            if(a[i] == 0)
                count0++;
        }
        if(count0 <= 1)
            count++;
        count0=0;
        if(n==0)
            break;
    }
    printf("%d",count);
    return 0;
}
