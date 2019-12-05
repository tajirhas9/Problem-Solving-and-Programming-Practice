#include <stdio.h>
int main()
{
    char s[5];
    int i,t;
    int sum=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        for(i=0;i<3;i++)
        sum += s[i];
        printf("sum = %d\n",sum);
        sum = 0;
    }
    return 0;
}
