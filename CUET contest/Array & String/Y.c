#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,len,count=0;
    char s[1000000];
    while(gets(s))
    {
        len = strlen(s);
        for(i = 0; s[i] != '\0'; i++)
        {
            if(((s[0] < 'A' && s[0] > 'Z') && (s[0] < 'a' && s[0] > 'z')))
            {
                continue;
            }
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                for(j = i; ((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z')); j++)
                {
                    i = j;
                }
                count++;
            }
            else
            {
                continue;
            }
        }
        printf("%d\n",count);
        count = 0;
    }
    return 0;
}
