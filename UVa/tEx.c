#include <stdio.h>
#include <string.h>
int main()
{
    int n,i=0,j,temp,count=0;
    char string[2000000];
    while(gets(string))
    {
        for(i = 0; i < strlen(string); i++)
        {
            if(string[i] == '"')
            {
                count++;
                if(count % 2 == 1)
                {
                    string[i] = '`';
                    for(j = strlen(string)+1; j >= i+1; j--)
                    {
                        string[j+1] = string[j];
                    }
                    string[i+1] = '`';
                }
                else
                {
                    string[i] = '\'';
                    for(j = strlen(string)+1; j >= i+1; j--)
                    {
                        string[j+1] = string[j];
                    }
                    string[i+1] = '\'';
                }
            }
            else
            {
                continue;
            }
        }
            for(i = 0; i < strlen(string); i++)
            {
                printf("%c",string[i]);
            }
            printf("\n");
    }
    return 0;
}
