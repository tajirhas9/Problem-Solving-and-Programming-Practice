#include <stdio.h>
int main()
{
    int i,n,a,b,max,min;
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d %d",&a,&b);
        if(a < b || (a+b)%2 != 0)
        {
            printf("impossible\n");
        }
        else
        {
            max = (a+b)/2;
            min = (a-b)/2;
            printf("%d %d\n",max,min);
        }
    }
    return 0;
}
