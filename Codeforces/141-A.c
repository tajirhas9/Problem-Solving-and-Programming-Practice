#include <stdio.h>
#include <string.h>
int main()
{
    char s1[110],a[110],s2[110];
    int i,countA[150],countB[150],l1,l2,l3;
    gets(s1);
    gets(s2);
    gets(a);
    for(i=65;i<91;i++)
    {
        countA[i] = 0;
        countB[i] = 0;
    }
    l1 = strlen(s1);
    l2 = strlen(s2);
    l3 = strlen(a);
    for(i=0;i<l1;i++)
        countA[s1[i]]++;
    for(i=0;i<l2;i++)
        countA[s2[i]]++;
    for(i=0;i<l3;i++)
        countB[a[i]]++;
    for(i=65;i<91;i++)
    {
        if(countA[i] != countB[i])
            break;
    }
    if(i==91)
        printf("YES");
    else
        printf("NO");
    return 0;
}
