#include <stdio.h>
int main()
{
    int m,n,s,i=0;
    scanf("%d %d",&m,&n);
    s = m*n;
    while(s > 0)
    {
        s = s-m-n+1;
        n--;
        m--;
        i++;
    }
    if(i%2==0)
        printf("Malvika");
    else
        printf("Akshat");
    return 0;
}
