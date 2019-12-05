#include <stdio.h>
int main()
{
    long int n;
    int binary[100];
    int i,j=0,r,t,count=0;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld",&n);
        while(n > 0)
        {
            binary[j] = n%2;
            n /= 2;
            if(binary[j] == 1)
                count++;
            j++;
        }
        if(count%2==0)
            printf("Case %d: even\n",i);
        else
            printf("Case %d: odd\n",i);
        count = 0;
    }
    return 0;
}
