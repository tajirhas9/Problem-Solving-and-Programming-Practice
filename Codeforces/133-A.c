#include <stdio.h>
#include <string.h>
int main()
{
    char s[110];
    int i,len;
    gets(s);
    len = strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9')
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
