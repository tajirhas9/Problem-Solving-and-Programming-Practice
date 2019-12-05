#include <stdio.h>
#include <string.h>
int main()
{
    char s[100000];
    int i,j,l,move=0,forward=0,reverse=0;
    gets(s);
    l = strlen(s);
    for(i=0; i<1; i++)
    {
        for(j='a'; j != s[i]; j++)
        {
            forward++;
            if(j > 122)
                j = 97;
        }
        for(j='a'; j != s[i];)
        {
            reverse++;
            j--;
            if(j < 97)
                j = 122;
        }
    }
        if(forward<reverse)
        {
            move += forward;
        }
        else
        {
            move += reverse;
        }
    forward = 0;
    reverse = 0;
    for(i=1; i<l; i++)
    {
        for(j=s[i-1]; j != s[i];)
        {
            forward++;
            j++;
            if(j > 122)
                j = 97;
        }
        for(j=s[i-1]; j != s[i];)
        {
            reverse++;
            j--;
            if(j < 97)
                j = 122;
        }
        if(forward<reverse)
        {
            move += forward;

        }
        else
        {
            move += reverse;
        }
        forward = 0;
        reverse = 0;
    }
    printf("%d",move);
    return 0;
}
