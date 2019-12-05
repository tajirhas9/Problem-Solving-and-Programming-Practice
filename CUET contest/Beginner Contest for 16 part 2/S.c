#include <stdio.h>
int main()
{
    int n,step;
    scanf("%d",&n);
    if(n <= 5)
    {
        step = 1;
    }
    else
    {
        if(n % 5 == 0)
        {
            step = n/5;
        }
        else
        {
            step = n/5;
            step++;
        }
    }
    printf("%d\n",step);
    return 0;
}
