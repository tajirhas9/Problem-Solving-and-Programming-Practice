#include <stdio.h>
int main()
{
    int n,i=1,j,count=0;
    while((scanf("%d",&n)))
    {
        if(n < 0) return 0;
        for(j = 1; j < n;)
        {
            j *= 2;
            count++;
        }
        printf("Case %d: %d\n",i,count);
        i++;
        count=0;
    }
    return 0;
}
