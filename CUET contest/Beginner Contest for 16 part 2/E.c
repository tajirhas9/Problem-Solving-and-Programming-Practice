#include <stdio.h>
#include <string.h>
int divide(char y[],int x)
{
    int mod,l,i,a;
    l = strlen(y);
    mod = y[0] - '0';
    for(i = 0; i < l-1;i++)
    {
        a = mod*10+(y[i+1]-'0');
        mod = a%x;
    }
    if(mod == 0)
        return 1;
    else
        return 0;
}
int main()
{
    int leap=0,hulu=0,bulu=0,l,i,z=0;
    char year[1000001];
    for(i = 0; i < 1000001; i++)
    {
        year[i] = '\0';
    }
    while(scanf("%s",year) == 1)
    {
        if(z!= 0)
            printf("\n");
        leap = 0;
        hulu = 0;
        bulu = 0;
        if((divide(year,400)) == 1 || (divide(year,4)) == 1 && (divide(year,100)) == 0)
        {
            leap = 1;
            printf("This is leap year.\n");
        }
        if((divide(year,15)) == 1)
        {
            hulu = 1;
            printf("This is huluculu festival year.\n");
        }
        if(leap == 1)
        {
            if((divide(year,55)) == 1)
            {
                bulu = 1;
                printf("This is bulukulu festival year.\n");
            }
        }
        if(leap == 0 && hulu == 0 && bulu == 0)
            printf("This is an ordinary year.\n");
        for(i = 0; i < l; i++)
        {
            year[i] = '\0';
        }
        z++;
    }
    return 0;
}
