#include<stdio.h>
int main()
{
    int t,i;
    long int a,b;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%ld%ld",&a,&b);
        printf("%ld\n",(a+b)/2);
    }
    return 0;
}
