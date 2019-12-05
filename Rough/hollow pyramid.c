#include <stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    k = (n/2);
    for(i = 0; i < n; i++)
    {
        if(i != (n-1))
        {
            for(j = 0; j < (1+(n-1)*2); j++)
            {
                if(j == k+i || j == k-i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        else
        {
            for(j = 0; j < (1+(n-1)*2); j++)
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
