#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i;
    char s1[150],s2[150];
    gets(s1);
    gets(s2);
    for(i=0; i<strlen(s1);i++)
    {
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
        if(s1[i] == s2[i])
            continue;
        else if(s1[i] > s2[i])
        {
            printf("1");
            return 0;
        }
        else
        {
            printf("-1");
            return 0;
        }
    }
    if(i==strlen(s1))
        printf("0");
    return 0;
}
