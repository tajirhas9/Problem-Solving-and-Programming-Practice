#include <stdio.h>
#include <string.h>
int main()
{
    int i=0,j=0,lines,counter=0,l[105],max;
    char s[105][105],a[105];
    max = l[0];
    while(gets(a))
    {
        l[i] = strlen(a);
        if(max < l[i])
        {
            max = l[i];
        }
        for(j=0 ; a[j] != '\0'; j++)
        {
            s[i][j] = a[j];
            if(a[j] == '\t') return 0;
        }
        i++;
        if(i >= 100)
        {
            break;
        }
    }
    lines = i;
    for(i = 0; i < max ;i++)
    {
        for(j = lines-1; j >= 0; j--)
        {
            if(s[j][i] == '\0')
            {
                printf(" ");
            }
            else
            {
                printf("%c",s[j][i]);
            }
        }
        printf("\n");
    }
    return 0;
}
