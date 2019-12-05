#include <stdio.h>
#include <string.h>
int main()
{
    int i,l,j;
    char s[150],temp;
    gets(s);
    l = strlen(s);
    for(i=0; i< l; i += 2)
    {
        for(j=i+2 ;j<l; j += 2)
        {
            if(s[i] > s[j])
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    puts(s);
    return 0;
}
