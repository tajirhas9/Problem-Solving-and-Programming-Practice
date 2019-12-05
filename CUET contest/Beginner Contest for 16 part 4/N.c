#include <stdio.h>
#include <string.h>
int main()
{
    char s[100000];
    int countA=0,countD=0,i,l;
    scanf("%d",&l);
    getchar();
    gets(s);
    for(i=0;i<l;i++)
    {
        if(s[i] == 'A')
            countA++;
        else
            countD++;
    }
    if(countA == countD)
        printf("Friendship");
    else if(countA>countD)
    printf("Anton");
    else
        printf("Danik");

    return 0;
}
