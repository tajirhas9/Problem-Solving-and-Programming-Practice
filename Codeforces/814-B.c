#include <stdio.h>
int main()
{
    int n,a[2000],b[2000],i,j,count=0,changeA[3000],changeB[3000],change=0,c,changeFor1=1;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
        scanf("%d",&b[i]);
    for(i=0; i<n; i++)
    {
        if(a[i] != b[i])
        {
            count++;
            c = i;
            changeA[change] = a[i];
            changeB[change] = b[i];
        }
    }
    if(count == 1)
    {
        while(changeA[change] == changeFor1 || changeB[change] == changeFor1)
          changeFor1++;
        a[c] = changeFor1;
    }
    else if(count == 2)
    {
        for(i=0; i<n; i++)
        {
            if(a[i] != b[i])
            {
                a[i] = b[i];
                break;
            }
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
