#include <stdio.h>
#include <string.h>
int main()
{
    int i,j = 1,count=0;
    char s[1000],s1[2000];
    gets(s);

    for(i = 0; i < strlen(s); i++)
    {
        s[i] = tolower(s[i]);
    }
    /*for(i = 0; i < strlen(s); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            continue;
        }
        else
        {
            return 0;
        }
    } */
    for(i = 0; i < 2*strlen(s);i++)
    {
        s1[i] = '.';
    }
    for(i = 0; i < strlen(s);i++)
    {
        if(s[i] != 'a'&& s[i] != 'e'&& s[i] != 'i'&& s[i] != 'o'&& s[i] != 'u' && s[i] != 'y')
        {
            s1[j] = s[i];
            j += 2;
            count++;
        }
    }
    s1[2*count] = '\0';
    printf("%s",s1);

    return 0;
}
