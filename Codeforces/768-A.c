#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
    int arrayStrength[100000],help = 0,n,i,j,count=0,smallest,greatest;
    scanf("%d",&n);
    if(n <= 100000)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d",&arrayStrength[i]);
            if(arrayStrength[i] > 1000000000)
            {
                return 0;
            }
        }
        smallest = arrayStrength[0];
        greatest = arrayStrength[0];
        for(i = 1; i < n; i++)
        {
            if(arrayStrength[i] < smallest)
            {
                smallest = arrayStrength[i];
            }
        }
        for(i = 1; i < n; i++)
        {
            if(arrayStrength[i] > greatest)
            {
                greatest = arrayStrength[i];
            }
        }
        for(i = 0; i < n; i++)
        {
            if(arrayStrength[i] == smallest || arrayStrength[i] == greatest)
            {
                count++;
            }
        }
        help = n-count;
        printf("%d",help);
    }
    return 0;
}
