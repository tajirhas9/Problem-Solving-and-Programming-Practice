#include <stdio.h>
#include <string.h>
int main()
{
    char s[120];
    int i,l1=500,l2=500,h=500,e=500,l=500,o=500;
    gets(s);
    l = strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i] == 'o')
        {
                o = i;
        }
    }
    for(i=0;i<l;i++)
    {
        if(s[i] == 'l')
        {
            if(l1 == 500 && i < o)
            {
                l2 = i;
            }
        }
    }
    for(i=0;i<l;i++)
    {
        if(s[i] == 'l')
        {
            if(i < l2)
                l1 = i;
        }
    }
    for(i=0;i<l;i++)
    {
        if(s[i] == 'e')
        {

            if(i < l1)
                e = i;
        }
    }
    for(i=0;i<l;i++)
    {
        if(s[i] == 'h')
        {
            if(i < e)
                h = i;
        }
    }
    if(h != 500 && e != 500 && l1 != 500 && l2 != 500 && o != 500)
    {
        if(e > h && e < l1)
        {
            if(l2 > l1)
            {
                if(o > l2)
                {
                    printf("YES");
                }
                else
                {
                    printf("NO");
                }
            }
            else
            {
                printf("NO");
            }
        }
        else
        {
            printf("NO");
        }
    }
    else
    {
        printf("NO");
    }
    /*printf("h=%d\ne=%d\nl1=%d\nl2=%d\no=%d\n",h,e,l1,l2,o);*/
    return 0;
}
