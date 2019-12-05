#include <stdio.h>
int main()
{
    int n,i,w1,w2;
    scanf("%d",&n);
    for(i = 1; w1 >= 0 && w2 >= 0; i++)
    {
        if(n%2 == 0)
        {
            w1 = (n/2)+1;
            w2 = n - w1;
            if(n == 2)
            {
                w1 = n/2;
                w2 = 0;
            }
        }
        else
        {
            w1 = n/2;
            w2 = n - w1;
        }
        printf("w1 = %d w2 = %d\n",w1,w2);
        if((w1 == 0 && w2 == 1) || (w1 == 1 && w2 == 0))
        {
            w1 = 0;
            w2 = 0;
            printf("w1 = %d w2 = %d\n",w1,w2);
            break;
        }
        if(w1 > w2)
        {
            n = w1;
        }
        else
        {
            n = w2;
        }
    }
}
