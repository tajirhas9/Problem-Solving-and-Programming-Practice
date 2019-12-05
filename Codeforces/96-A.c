#include <stdio.h>
int main()
{
    char s[101];
    int i,l,count=0;
    gets(s);
    l = strlen(s);
    l--;
    while(l >= 0)
    {
        if(s[l] == '0')
        {
            while(s[l] == '0')
            {
                count++;
                if(count >= 7)
                {
                    printf("YES");
                    return  0;
                }
                    l--;
                    if(l < 0) break;
            }
        }
        else
        {
            while(s[l] == '1')
            {
                count++;
                if(count >= 7)
                {
                    printf("YES");
                    return 0;
                }
                l--;
                if(l < 0) break;
            }
        }
        count = 0;
    }
    printf("NO");
    return 0;
}
