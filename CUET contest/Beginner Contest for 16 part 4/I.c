#include <stdio.h>
#include <string.h>
int main()
{
    char s[120],t[120];
    int i,l1,l2,j;
    gets(s);
    gets(t);
    l1 = strlen(s);
    l2 = strlen(t);
    for(i=0,j=(l2-1); i < l1;i++,j--)
    {
        if(s[i] == t[j])
            continue;
        else
            break;
    }
    j++;
    if(i == l1 && j == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
