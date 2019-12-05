#include <stdio.h>
int main()
{
    int n,i=1,count=0;
    scanf("%d",&n);
    while(n >= 0)
    {
        if(n <= 0)
        {
            break;
        }
        count++;
        if(i%2 == 0)
        {
            n--;
        }
        else
        {
            n -= 2;
        }
        i++;
    }
    printf("%d",count);
    return 0;
}
