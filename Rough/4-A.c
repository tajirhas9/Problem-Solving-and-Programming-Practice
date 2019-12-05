#include <stdio.h>
#include <string.h>
int main()
{
    int i=0,n;
    char s[100];
    scanf("%d",&n);
    while(i <= n)
    {
        gets(s);
        if(strlen(s) > 10)
        {
            printf("%c%d%c\n",s[0],(strlen(s)-2),s[strlen(s)-1]);
        }
        else
        {
            printf("%s\n",s);
        }
        i++;
    }
    return 0;
}
