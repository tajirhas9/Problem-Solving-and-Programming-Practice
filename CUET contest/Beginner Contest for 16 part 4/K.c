#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[110];
    int i,l,count=0,alphabet[150];
    scanf("%d",&l);
    getchar();
    gets(s);
    if(l < 26)
    {
        printf("NO");
        return 0;
    }
    else
    {

        for(i=0; i<l; i++)
        {
            s[i] = tolower(s[i]);
        }
        for(i=97;i<123;i++)
            alphabet[i] = 0;
        for(i=0; i<l; i++)
        {
            alphabet[s[i]]++;
        }
        for(i=97; i<123; i++)
        {
            if(alphabet[i] > 0)
                count++;
        }
        if(count==26)
            printf("YES");
        else
            printf("NO");

    }
    return 0;
}
