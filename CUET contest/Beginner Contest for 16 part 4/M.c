#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[120];
    int i,l,countUp=0,countLow=0;
    gets(s);
    l = strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            countUp++;
        else
            countLow++;
    }
    if(countUp <= countLow)
    {
        for(i=0;i<l;i++)
        {
            s[i] = tolower(s[i]);
        }
    }
    else
    {
        for(i=0;i<l;i++)
            s[i] = toupper(s[i]);
    }
    puts(s);
    return 0;
}
