#include <stdio.h>
int main()
{
    unsigned long long int girls[100000],chimp_height;
    int i,mid,begin,end,n,q,height,flag=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%llu",&girls[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%llu",&chimp_height);
        begin = 0;
        end = n-1;
        while(begin <= end)
        {
            mid = begin+(begin+end)/2;
            if(girls[mid] == chimp_height)
            {
                begin = mid;
                if(begin > 0 && begin < (n-1))
                printf("%llu %llu\n",girls[begin-1],girls[begin+1]);
            else if(begin >= (n-1))
                printf("%llu X\n",girls[begin-1]);
            else
                printf("X %llu\n",girls[begin+1]);
                flag = 1;
                break;
            }
            if(girls[mid] < chimp_height)
                begin = mid+1;
            else if(girls[mid] > chimp_height)
                end = mid-1;
        }
        if(flag == 0)
        {
            if(begin > 0 && begin <= (n-1))
                printf("%llu %llu\n",girls[begin-1],girls[begin]);
            else if(begin > (n-1))
                printf("%llu X\n",girls[begin-1]);
            else
                printf("X %llu\n",girls[begin]);
        }
        flag = 0;
    }
    return 0;
}
