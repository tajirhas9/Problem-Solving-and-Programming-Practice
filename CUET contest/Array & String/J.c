#include <stdio.h>
int cycleLength(unsigned long int x)
{
    unsigned long int count=0;
    if(x == 1)
    {
        count = 1;
        return count;
    }
    else if(x == 0)
    {
        return count;
    }
    else
    {
        while(x != 1)
        {
            if(x%2 == 0)
            {
                x /= 2;
                count++;
            }
            else
            {
                x = 3*x + 1;
                count++;
            }
            if(x == 1)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    unsigned long int a,i,j,temp,c,l,x,flag=0;
    unsigned long int count[20000];
    while((scanf("%lu %lu",&i,&j)) == 2)
    {
            if(i > j)
            {
                temp = i;
                i = j;
                j = temp;
                flag++;
            }
            x = i;
            for( ; x <= j; x++)
            {
                c = cycleLength(x);
                count[x] = c;
            }
            l = count[i];
            for(x = i; x <= j; x++)
            {
                if(l < count[x])
                {
                    l = count[x];
                }
            }
            if(flag == 1)
            {
                printf("%lu %lu %lu\n",j,i,l);
            }
            else
            {
                printf("%lu %lu %lu\n",i,j,l);
            }
        flag = 0;
    }
    return 0;
}
