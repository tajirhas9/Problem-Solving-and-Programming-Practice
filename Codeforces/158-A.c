#include <stdio.h>
int main()
{
    int n,k,i,j=0,result;
    int a[1001];
    scanf("%d %d",&n,&k);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    if(a[0] == 0)
    {
        printf("%d",0);
        return 0;
    }
    i = k;
    if(a[k] != 0)
    {
        while(a[i] == a[k-1])
        {
            k++;
            i++;
        }
    }
    else
    {
        while(a[i-1] == 0)
        {
            k--;
            i--;
            if(i  < 0) break;
        }
    }
    printf("%d",k);
    return 0;
}
