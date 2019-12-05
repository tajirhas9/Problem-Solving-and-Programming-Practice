#include <stdio.h>
#include <string.h>
int main()
{
    char s1[110],s2[110],temp[110];
    int i,j;
    scanf("%s %s",s1,s2);
    for(i=(strlen(s2)-1),j=0;i>=0;i--,j++)
    {
        temp[j] = s2[i];
    }
    temp[j] = '\0';
    for(i=0;i<strlen(s1);i++)
    {
        if(s1[i] != temp[i])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
