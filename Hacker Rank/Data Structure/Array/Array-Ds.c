#include <stdio.h>
int main()
{
    int b[1100],n,j;
    scanf("%d",&n);
    for(j=(n-1);j>=0;j--)
    {
        scanf("%d",&b[j]);
    }
    for(j=0;j<n;j++)
        printf("%d ",b[j]);
    return 0;
}
