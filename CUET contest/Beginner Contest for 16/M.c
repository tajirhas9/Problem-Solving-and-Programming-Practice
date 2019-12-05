#include <stdio.h>
#include <math.h>
int main()
{
    int t,i,n;
    int total;
    scanf("%d",&t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d",&n);
        total = n;
        total *= 567;
        total /= 9;
        total +=  7492;
        total *= 235;
        total /= 47;
        total -= 498;
        total = total / 10;
        total = total % 10;
        printf("%d\n",abs(total));
    }
    return 0;
}
