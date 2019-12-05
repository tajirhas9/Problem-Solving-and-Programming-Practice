#include <stdio.h>
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n>=120)
            printf("Good Boy Sifat\n");
        else
            printf("Naughty Boy Sifat\n");
        if(t==0)
            break;
    }
    return 0;
}
