#include <stdio.h>
int main()
{
    int a,b,n,count=0;
    scanf("%d",&a);
    scanf("%d",&b);
    if((a >= 1 && a <= 10) && (b >= 1 && b <= 10))
    {
        while(a <= b)
        {
            a *= 3;
            b*= 2;
            count++;
        }
        printf("%d",count);
    }
    else
    {
        return 0;
    }
    return 0;
}
