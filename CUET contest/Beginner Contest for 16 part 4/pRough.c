#include <stdio.h>
#include <string.h>
int main()
{
    char s[1100000];
    int i,j,l;
    int flagAB=0,flagBA=0;
    gets(s);
    l = strlen(s);
    for(i=0; i<l; i++)
    {
        if(s[i] == 'A')
        {
            if(s[i+1] == 'B')
            {
                for(j=i+2; j<l; j++)
                {
                    if(s[j] == 'B')
                    {
                        if(s[j+1] == 'A')
                        {
                            flagAB++;
                            flagBA++;
                            break;
                        }
                    }

                }
            }
        }
        else if(s[i] == 'B')
        {
            if(s[i+1] == 'A')
            {
                for(j=i+2; j<l; j++)
                {
                    if(s[j] == 'A')
                    {
                        if(s[j+1] == 'B')
                        {
                            flagAB++;
                            flagBA++;
                            break;
                        }
                    }
                }
            }
        }
        if(flagAB == 1 && flagBA == 1)
            break;
    }
    if(flagAB == 1 && flagBA == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
