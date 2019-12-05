#include <stdio.h>
#include <string.h>
int main()
{
    char s[55];
    int len,i,j,count=0;
    scanf("%d",&len);
    scanf("%s",s);
    for(i=0;i<len;i++)
    {
        for(j=i+1;s[i] == s[j];j++)
        {
            count++;
        }
        i = j-1;
    }
    printf("%d",count);
    return 0;
}
