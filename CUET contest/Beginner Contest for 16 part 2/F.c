#include <stdio.h>
int main()
{
    char s[100];
    int i,sum=0,fin=0;
    while(gets(s))
    {
        if(strlen(s)  <= 1)
        {
            if(s[0] - '0' == 0)
            {
                return 0;
            }
            else
            {
                printf("%d\n",(s[0] - '0'));
                continue;
            }
        }
        for(i = 0; i < strlen(s);i++)
        {
            sum += s[i] - '0';
        }
        if(sum <= 9) fin = sum;
        else
        {
            while(sum > 9)
            {
                fin = (sum/10)+(sum%10);
                sum = fin;
            }
        }
        printf("%d\n",fin);
        sum = 0;
        fin = 0;
    }
    return 0;
}
