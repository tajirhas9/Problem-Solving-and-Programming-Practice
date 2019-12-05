#include <stdio.h>
int main()
{
    int i,n,a,b;
    scanf("%d",&n);
    if(n < 1 && n >= 15)
    {
        return 0;
    }
    for(i = 1; i <= n; i++)
    {
        scanf("%d %d",&a,&b);
        if((a > -1000000001 && a < 1000000001) && (b > -1000000001 && b < 1000000001))
        if(a>b)
        {
            printf(">\n");
        }
        else if(a == b)
        {
            printf("=\n");
        }
        else
        {
            printf("<\n");
        }
    }
    return 0;
}
