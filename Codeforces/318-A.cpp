#include <stdio.h>
int main()
{
    unsigned long long int n,k,i,c=1,p=0;
    scanf("%llu %llu",&n,&k);
    if(n%2==1)
    {
        if(k <= (n/2)+1)
        {
            p = 1+(k-1)*2;
        }
        else
        {
            p = 2+(k-((n/2)+1)-1)*2;
        }
    }
    else
    {
        if(k <= (n/2))
        {
            p = 1+(k-1)*2;
        }
        else
        {
            p = 2+(k-((n/2))-1)*2;
        }
    }
    printf("%llu",p);
        return 0;
}

