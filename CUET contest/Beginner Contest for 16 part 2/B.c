#include<stdio.h>
int main()
{
    int n,t,a[100],i,j,max;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d",&n);
        for(j=0; j<n; j++)
            scanf("%d",&a[j]);
        max = a[0];
        for(j=0; j < n; j++)
        {
            if(max < a[j])
                max = a[j];
        }
        printf("Case %d: %d\n",i,max);
    }
    return 0;
}

