#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    char s[150];
    int i,j,k,t,l,mid,x;
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        scanf("%s",s);
        l = strlen(s);
        /*if(l%2 == 0)
        {
            printf("No\n");
            continue;
        }*/
        mid = (l-1)/2;
        for(j=0;j<l;j++)
        {
            s[j] = tolower(s[j]);
        }
        for(j=0,k=(l-1);j <= mid; j++,k--)
        {
            if((s[j] >= 'a' && s[j] <= 'z'))
            {
                if(s[j] == s[k])
                {
                    continue;
                }
                else
                    break;
            }
            else if(s[j] >= '0' && s[j] <= '9')
            {
                if(s[j] == s[k])
                {
                    continue;
                }
                else
                    break;
            }
            else
            {
                break;
            }
        }
        if(j == (mid+1))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
