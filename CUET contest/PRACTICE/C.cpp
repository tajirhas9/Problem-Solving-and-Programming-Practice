#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000000];
    long long int l,sum=0,i;
    scanf("%[^'\0']s",s);
    l = strlen(s);
    for(i=0; i<l; i++)
    {
        if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
        {
            sum += s[i] - '0';
        }
        else if(s[i] == 'b')
        {
            while(sum--)
            {
                printf(" ");
                if(sum==0)
                    break;
            }
        }
        else if(s[i] == '!')
        {
            printf("\n");
        }
        else if(s[i] == '\n')
            printf("\n");
        else
        {
            while(sum--)
            {
                printf("%c",s[i]);
                if(sum==0)
                    break;
            }
        }
    }
    printf("\n");
    return 0;
}
