#include <stdio.h>

int main()
{
    int total=0,n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        total = n;
        if(n == 1 || n == 2 || n%2==1)
            printf("%d\n",n);
        else
            printf("%d\n",n+1);
        if(t==0)
        break;
    }
    return 0;
}

