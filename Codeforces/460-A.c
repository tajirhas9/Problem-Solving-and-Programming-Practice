#include <stdio.h>
int main()
{
    int n,m,i,day;
    scanf("%d %d",&n,&m);
    for(i=1;n > 0;i++)
    {
        n--;
        if(i%m==0)
            n++;
    }
    printf("%d",i-1);
    return 0;
}
