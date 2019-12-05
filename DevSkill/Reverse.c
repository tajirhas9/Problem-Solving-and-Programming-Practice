#include <stdio.h>
#include <string.h>
int main()
{
    char s[1100],s1[1100];
    int i,j,t,l;
    scanf("%d",&t);
    getchar();
    while( t > 0)
    {
        scanf("%[^\n]s",s);
        getchar();
        l = strlen(s);
        for(i=(l-1),j=0; i >= 0; i--,j++)
        {
            s1[j] = s[i];
        }
        s1[l] = '\0'; /*'\0' at the last of the string*/
        printf("%s\n",s1);
        t--;
    }
    return 0;
}
