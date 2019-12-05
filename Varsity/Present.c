#include <stdio.h>
int main()
{
    int n,i,l;
    int p[120];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&l);
        p[l] = i;
    }
    for(i=1;i<=n;i++)
        printf("%d ",p[i]);
    return 0;
}
