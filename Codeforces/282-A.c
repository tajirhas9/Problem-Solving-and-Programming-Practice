#include <stdio.h>
#include <string.h>
int main()
{
    int x=0,t,i;
    char s[5];
    scanf("%d",&t);
    getchar();
    for(i = 1; i <= t; i++)
    {
        gets(s);
        if((s[0] == 'X' && s[1] == '+' && s[2] == '+') || (s[0] == '+' && s[1] == '+' && s[2] == 'X'))
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    printf("%d",x);
    return 0;
}
