#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int c,n[40],len,dec=0,i,pow=1,j,count=0;
    char num[40];
    for(i = 0; i < 40; i++)
    {
        num[i] = '0';
        n[i] = 0;
    }
    while(gets(num))
    {
        len = strlen(num);
        if(len == 1 && num[0] == '0')
        {
            return 0;
        }
        for(i = 0; i < len; i++)
        {
            n[i] = num[i] - '0';
        }
        for(i = 0; len > 0; len--,i++)
        {
            for(j = 1; j <= len; j++)
            {
                pow *= 2;
            }
            dec += n[i]*(pow-1);
            pow = 1;
        }
        printf("%d\n",dec);
        dec = 0;
        pow = 1;
        for(i = 0; i < 40; i++)
        {
            num[i] = '0';
            n[i] = 0;
        }
    }
    return 0;
}
