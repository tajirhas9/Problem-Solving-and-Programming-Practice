#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i,l,flag=0;
    char s[150];
    gets(s);
    l = strlen(s);
    if(s[0] >= 'a' && s[0]<= 'z')
    {
        for(i=1; i<l; i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(i == l)
            flag++;
    }
    else
    {
        for(i=0; i<l; i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(i == l)
            flag++;
    }
    if(flag == 1)
    {
        for(i=0; i < l; i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] = tolower(s[i]);
            else
                s[i] = toupper(s[i]);
        }
    }
    puts(s);
    return 0;
}
