#include <stdio.h>
#include <string.h>
int main()
{
    char input[201],output[301];
    int i,j,k,m=0,n,x,count=0,s=0;

    for(k = 0; k < 301; k++)
    {
        output[k] = '\0';
    }
    for(k = 0; k < 201; k++)
    {
        input[k] = '\0';
    }

    scanf("%d",&n);
    getchar();
    for(i = 1; i <= n; i++)
    {
        gets(input);
        for(j = 0; j < strlen(input); j++)
        {
            if(input[j] >= 'A' && input[j] <= 'Z')
            {
                for(k = j+1; input[k] >= '0' && input[k] <= '9'; k++)
                {
                    count++;
                }
                if(count == 3)
                {
                    x = (input[j+1] - '0')*100 + (input[j+2] - '0')*10 + (input[j+3] - '0');
                }
                else if(count == 2)
                {
                    x = (input[j+1] - '0')*10 + (input[j+2] - '0');
                }
                else if(count == 1)
                {
                    x = (input[j+1] - '0');
                }
            }
            else
            {
                continue;
            }
            for(m=0 ; m < x; m++)
            {
                output[s] = input[j];
                s++;
            }
            count = 0;
        }
        printf("Case %d: %s\n",i,output);
        for(k = 0; k < 301; k++)
        {
            output[k] = '\0';
        }
        for(k = 0; k < 201; k++)
        {
            input[k] = '\0';
        }
        s=0;
    }
    return 0;
}
