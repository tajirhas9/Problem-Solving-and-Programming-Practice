#include <stdio.h>
#include <string.h>
int main()
{
    char s[220],t[220];
    int i,l,j=0;
    gets(s);
    l= strlen(s);
    for(i=0;i<=l;i++)
    {
        if(s[i] == '\0')
        {
            t[j] = '\0';
            break;
        }
        if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
        {
            i += 2;
        }
        else
        {
            t[j] = s[i];
            j++;
        }
        if((s[i+1] == 'W' && s[i+2] == 'U' && s[i+3] =='B') && t[j-1] != ' ')
        {
            t[j] = ' ';
            j++;
        }
    }
    puts(t);
    return 0;
}
