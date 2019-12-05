#include <stdio.h>
int main()
{
    long long int n,m,time=0,tpp,i,workingFrom,workingTo,flag=0,check;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&tpp);
        time += tpp;
    }
    scanf("%lld",&m);
    if(m == 0)
        check = -1;
    for(i=1;i<=m;i++)
    {
        scanf("%lld %lld",&workingFrom,&workingTo);
        if(flag == 0)
        {
            if(workingFrom == time)
            {
                check = workingFrom;
                flag = 1;
            }
            else if(workingFrom > time)
            {
                check = workingFrom;
                flag = 1;
            }
            else if(time > workingFrom && time <= workingTo)
            {
                check = time;
                flag = 1;
            }
            else if(i == m && time <= workingTo)
                check = time;
            else if(i == m && time > workingTo)
                check = -1;
        }
    }
    printf("%lld",check);
    return 0;
}
