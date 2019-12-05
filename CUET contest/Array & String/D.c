#include <stdio.h>
int main()
{
    int i=0,j=0,lines,counter=0,l[105],max;
    char s[105][105],a[105];
    int count[100];

    while(gets(a))
    {
        l[i] = strlen(a);
        if(max < l[i])
        {
            max = l[i];
        }
        for(j=0 ; a[j] != '\0'; j++)
        {
            s[i][j] = a[j];
        }
        i++;
    }


    return 0;
}
