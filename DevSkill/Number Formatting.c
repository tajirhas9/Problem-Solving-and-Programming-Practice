#include <stdio.h>
int main()
{
    char s[20];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        if(s[0] == '8')
        {
            switch(s[4])
            {
            case '6':
                printf("%s Airtel\n",s);
                break;
            case '7':
                printf("%s Grameenphone\n",s);
                break;
            case '5':
                printf("%s Teletalk\n",s);
                break;
            case '8':
                printf("%s Robi\n",s);
                break;
            case '9':
                printf("%s Banglalink\n",s);
                break;
            case '1':
                printf("%s Citycell\n",s);
                break;
            }
        }
        if(s[0] == '0')
        {
            switch(s[2])
            {
            case '6':
                printf("88%s Airtel\n",s);
                break;
            case '7':
                printf("88%s Grameenphone\n",s);
                break;
            case '5':
                printf("88%s Teletalk\n",s);
                break;
            case '8':
                printf("88%s Robi\n",s);
                break;
            case '9':
                printf("88%s Banglalink\n",s);
                break;
            case '1':
                printf("88%s Citycell\n",s);
                break;
            }
        }
        if(t==0)
            break;
    }
    return 0;
}
