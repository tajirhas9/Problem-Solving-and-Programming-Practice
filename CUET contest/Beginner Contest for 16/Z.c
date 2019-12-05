#include <stdio.h>
int main()
{
    int a,i,count=0,length=0;
    int array[40];
    for(i = 0; i < 40; i++)
    {
        array[i] = -1;
    }
    i = 0;
    while(1)
    {
        scanf("%d",&a);
        if(a == 0)
        {
            break;
        }
        else if(a >= 1 && a <=  2147483647)
        {
            while(a >= 1)
            {
                array[i] = a%2;
                a /= 2;
                i++;
            }
            i = 0;
            while(array[i] != -1)
            {
                if(array[i] == 1)
                {
                    count++;
                }
                length++;
                i++;
            }
            i = length-1;
            printf("The parity of ");
            while(i >= 0)
            {
                printf("%d",array[i]);
                i--;
            }
            printf(" is %d (mod 2).\n",count);

        }
        else
        {
            return 0;
        }
        count = 0;
        for(i = 0; i < 40;i++)
        {
            array[i] = -1;
        }
        i = 0;
        length = 0;
    }

    return 0;
}
