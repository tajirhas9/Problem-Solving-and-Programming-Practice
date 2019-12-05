#include <stdio.h>
int main()
{
    int i,j,k,space,n;
    scanf("%d",&n);
    for(i = 1; i <= n; i+=2)
    {
        for(j = 1;j <= n; j++)
        {
            space = (i-1)/2;
            if(n%2 == 0 && i == n)
            {
                space++;
            }
            for(k = 1; k <= space; k++,j++)
            {
                printf(" ");
            }
            for( ; j <= (n-space);j++)
            {
                printf("*");
            }
            for( ; j <= n; j++)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
