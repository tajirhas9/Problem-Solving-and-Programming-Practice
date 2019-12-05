#include <stdio.h>
#include <string.h>
int main()
{
    char s[55],sub[55],a[55];
    int l,count=1,i,temp,j;
    gets(s);
    l = strlen(s);
    if(l == 1)
    {
        printf("%d",count);
        return 0;
    }
    strcpy(a,s);
    while(1)
    {
        for(i=1,j=0;i<l;i++,j++)
        {
            sub[0] = s[l-1];
            sub[i] = s[j];
            if(i == l-1)
            {
                sub[i+1] = '\0';
            }
        }
        strcpy(s,sub);
        if(strcmp(sub,a) == 0)
            break;
        else
            count++;
    }
    printf("%d",count);
    return 0;
}
