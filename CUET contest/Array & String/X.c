#include <stdio.h>
#include <string.h>
int main()
{
    char s[999900],b[999900];
    int i,j,temp;
    while(gets(s))
    {
        for(i = 0,j = 0; i < strlen(s);i++,j++)
        {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                if(s[i] != 'A' && s[i] != 'a' && s[i] != 'E' && s[i] != 'e' && s[i] != 'I' && s[i] != 'i' && s[i] != 'O' && s[i] != 'o' && s[i] != 'U' && s[i] != 'u')
                {
                    temp = i;
                    for( ; ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')); i++,j++)
                    {
                        b[j] = s[i+1];
                        if(b[j] == '\0')
                        {
                            b[j] = ' ';
                        }
                    }
                    j--;
                    i--;
                    b[j] = s[temp];
                    j++;
                    b[j] = 'a';
                    j++;
                    b[j] = 'y';

                }
                else
                {
                    for( ; ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')); i++,j++)
                    {
                        b[j] = s[i];
                        if(b[j] == '\0')
                        {
                            b[j] = ' ';
                        }
                    }
                    i--;
                    b[j] = 'a';
                    j++;
                    b[j] = 'y';
                }
            }
            else
            {
                b[j] = s[i];
            }
        }
        printf("%s\n",b);
    }
    return 0;
}
