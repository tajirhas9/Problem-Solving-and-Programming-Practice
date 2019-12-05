#include <stdio.h>
#include <string.h>
int main()
{
    char s[101],p,l,k,check[101];
    int j=1,i,count=0,score=0,n;
    scanf("%d",&n);
    getchar();
    for(j = 1; j <= n; j++)
    {
        scanf("%s",s);
        for(i = 0; i < strlen(s); i++)
        {
            if(s[i] == 'O')
            {
                count++;
                score += count;
            }
            else if(s[i] == 'X')
            {
                count = 0;
            }
        }
        printf("%d\n",score);
        count = 0;
        score = 0;
    }
    return 0;
}
