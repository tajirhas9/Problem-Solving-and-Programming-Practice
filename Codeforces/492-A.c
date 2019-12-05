#include <stdio.h>
int main()
{
    int n,i,j,height,used=0;
    scanf("%d",&n);
    i = 1;
    while(used <= n)
    {
        for(j=1;j<=i;j++)
        {
            used += j;
        }
        i++;
        height++;

    }
    printf("%d",height-1);
    return 0;
}
