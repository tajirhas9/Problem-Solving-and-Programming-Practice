#include <stdio.h>
#include <string.h>
int main()
{
    char s1[100000],s2[100000],big[100000],small[100000];
    int l,s,l1,l2,i,j,flag=0;
    gets(s1);
    gets(s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    if(l2>l1)
    {
        strcpy(big,s2);
        strcpy(small,s1);
    }
    else
    {
        strcpy(big,s1);
        strcpy(small,s2);
    }
    l2 = strlen(big);
    l1 = strlen(small);
    for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;j++)
        {
            if(small[i] == big[j])
            {
                flag++;
                goto print;
            }
            else
                continue;
        }
    }
    print:
        if(flag == 0)
            printf("-1");
        else
            printf("%d",l2);
    return 0;
}
