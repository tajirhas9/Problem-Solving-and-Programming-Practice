#include <stdio.h>
#include <string.h>
int main()
{
    char n1[250],n2[250],revN1[250],revN2[250];
    int t,i,j,sum[250],d;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        scanf("%s %s",n1,n2);
        for(i=0,j=(strlen(n1)-1);i<strlen(n1);i++,j--)
        {
            revN1[i] = n1[j];
        }
        revN1[i] = '\0';
        for(i=0,j=(strlen(n2)-1);i<strlen(n2);i++,j--)
        {
            revN2[i] = n2[j];
        }
        revN2[i] = '\0';
        if(strlen(revN1)>strlen(revN2))
        {
            d = strlen(revN1)-strlen(revN2);
            for(i=(strlen(revN2));i>=0;i--)
            {
                revN2[i+d] = revN2[i];
            }
            for(i=0;i<d;i++)
                revN2[i] = '0';
        }
        else if(strlen(revN2)>strlen(revN1))
        {
            d = strlen(revN2)-strlen(revN1);
            for(i=(strlen(revN1));i>=0;i--)
            {
                revN1[i+d] = revN1[i];
            }
            for(i=0;i<d;i++)
                revN1[i] = '0';
        }
        for(i=(strlen(revN1)-1),j=0;i>=0;i--,j++)
        {
            if(((revN1[i]-'0')+(revN2[i]-'0')) >= 10)
            {
                sum[j] = ((revN1[i]-'0')+(revN2[i]-'0'))%10;
                revN1[i-1] += ((revN1[i]-'0')+(revN2[i]-'0'))/10;
                if(i==0)
                {
                    sum[j+1] = ((revN1[i]-'0')+(revN2[i]-'0'))/10;
                    j++;
                }
            }
            else
            {
                sum[j] = ((revN1[i]-'0')+(revN2[i]-'0'))%10;

            }
        }
        i=0;
        if(sum[0] == 0)
            while(sum[i] == 0)
                i++;
        for( ;i<j;i++)
        {
            printf("%d",sum[i]);
        }
        printf("\n");
        if(t==0)
            break;
    }
    return 0;
}
