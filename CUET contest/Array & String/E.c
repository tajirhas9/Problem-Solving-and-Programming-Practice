#include <stdio.h>
int main()
{
    long long int s[10001],n;
    long long int count[10];
    int t,i,c,j,thousand;

    for(i = 0; i < 10; i++)
    {
        count[i] = 0;
    }

    scanf("%d",&t);
    if(t >= 1 && t <= 20)
    {
        for(j = 1; j <= t; j++)
        {
            scanf("%ld",&n);
            if(n > 1 && n < 10000)
            {
                for(i = 1; i <= n; i++)
                {
                    s[i] = i;
                }
                for(i = 1; i <= n; i++)
                {
                    if(i < 10)
                    {
                        count[s[i]]++;
                    }
                    else if(i >= 10 && i < 100)
                    {
                        c = s[i]/10;
                        count[c]++;
                        c = s[i]%10;
                        count[c]++;
                    }
                    else if(i >= 100 && i < 1000)
                    {
                        c = s[i]/100;
                        thousand = c;
                        count[c]++;
                        c = s[i]%10;
                        count[c]++;
                        c = s[i]/10-(thousand*10);
                        count[c]++;
                    }
                    else if(i >= 1000 && i < 10000)
                    {
                        c = s[i]/1000;
                        thousand = c;
                        count[c]++;
                        c = s[i]%10;
                        count[c]++;
                        c = s[i]/100-(thousand*10);
                        count[c]++;
                        c = s[i];
                        c /= 10;
                        c %= 10;
                        count[c]++;
                    }
                    else
                    {
                        break;
                    }
                }
                for(i = 0 ; i < 10; i++)
                {
                    if(i != 9)
                    {
                        printf("%ld ",count[i]);
                    }
                    else
                    {
                        printf("%ld",count[i]);
                    }
                }
            }
            else
            {
                break;
            }
            printf("\n");
            for(i = 0; i < 10; i++)
            {
                count[i] = 0;
            }
        }
    }
    return 0;
}
