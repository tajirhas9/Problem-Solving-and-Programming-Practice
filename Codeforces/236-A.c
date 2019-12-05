#include <stdio.h>
#include <string.h>
int main()
{
    char s[110];
    int l,i,j,k;
    scanf("%s",s);
    l = strlen(s);
    for(i=0;i<strlen(s);i++)
    {
        for(j=i+1;j<strlen(s);j++)
        {
            if(s[j] == s[i])
            {

                for(k=j;k<=l;k++)
                {
                    s[k] = s[k+1];
                }
            }
        }
    }
    for(i=0;i<strlen(s);i++)
    {
        for(j=i+1;j<strlen(s);j++)
        {
            if(s[j] == s[i])
            {

                for(k=j;k<=l;k++)
                {
                    s[k] = s[k+1];
                }
            }
        }
    }
    if(strlen(s)%2==0)
        printf("CHAT WITH HER!");
    else
        printf("IGNORE HIM!");
    return 0;
}
