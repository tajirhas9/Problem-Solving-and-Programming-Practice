#include <stdio.h>
int main()
{
    int i,n,total=0,max=0,a;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&a);
        if(max < a)
        {
            max = a;
        }
        total += a;
    }
    printf("%d\n",(n*max)-total);
    return 0;
}
