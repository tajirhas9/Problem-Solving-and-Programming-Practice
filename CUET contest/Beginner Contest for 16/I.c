#include <stdio.h>
int main()
{
    int a,i,count=0,length=0;
    int array[100];
    for(i = 0; i < 100; i++)
    {
        array[i] = -2;
    }
    i = 0;
    while(1)
    {
        scanf("%d",&a);
        if(a <= -1)
        {
            return 0;
        }
        else if(a >= 0 && a <  1000000001)
        {
            if(a == 0)
            {
                printf("0\n");
                continue;
            }
            else
            {
                while(a >= 1)
                {
                    array[i] = a%3;
                    a /= 3;
                    i++;
                }
                i = 0;
                while(array[i] != -2)
                {
                    length++;
                    i++;
                }
                i = length-1;
                while(i >= 0)
                {
                    printf("%d",array[i]);
                    i--;
                }
            }
            printf("\n");
        }
        else
        {
            break;
        }
        for(i = 0; i < 100; i++)
        {
            array[i] = -2;
        }
        i = 0;
        length = 0;
        count++;
        if(count == 99)
        {
            break;
        }
    }

    return 0;
}
