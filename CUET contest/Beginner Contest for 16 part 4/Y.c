#include <stdio.h>
#include <string.h>
int main()
{
    char s1[2100],s2[2100];
    int i,x,l,j,n;
    scanf("%d",&n);
    getchar();
    gets(s1);
    l = strlen(s1);
    if(l%2 != 0)
    {
        for(i=(l-2),j=0; i >= 1; i-=2,j++)
        {
            s2[j] = s1[i];
        }
        for(i=0;i < l;i+=2,j++)
        {
            s2[j] = s1[i];
        }
    }
    else
    {
        for(i=(l-2),j=0;i >= 0;i-=2,j++)
        {
            s2[j] = s1[i];
        }
        for(i=1;i<l;i+=2,j++)
        {
            s2[j] = s1[i];
        }
    }
    s2[l] = '\0';
    puts(s2);
    return 0;
}
