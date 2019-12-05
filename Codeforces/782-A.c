#include <stdio.h>
int main()
{
    int on_the_table=0,i,j,n;
    int socks[200000],socks_check[100000];
    /*
    *Inputs
    */
    scanf("%d",&n);
    for(i = 0; i < 2*n;i++)
    {
        scanf("%d",&socks[i]);
    }
    /*
    *Check Pair
    */
    for(i = 0; i < n; i++)
    {
        socks_check[i] = 0;
    }
    for(i = 0; i < 2*n; i++)
    {
        socks_check[socks[i]]++;
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ",socks_check[i]);
    }
    for(i = 0; i < n; i++)
    {
        if(socks_check[i] != 2)
        {
            printf("\nInvalide input");
            return 0;
        }
    }
    printf("\nValide input");

    return 0;
}
