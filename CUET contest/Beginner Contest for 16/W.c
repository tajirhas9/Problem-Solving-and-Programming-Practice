#include <stdio.h>
#include <string.h>
int main()
{
    int j,i=0,n,stroke=0;
    char s[100];
    scanf("%d",&n);
    while(gets(s))
    {
        for(j = 0; j < strlen(s); j++)
        {
            switch(s[j])
            {
            case 'a':
            case 'd':
            case 'g':
            case 'j':
            case 'm':
            case 'p':
            case 't':
            case 'w':
            case ' ':
                stroke += 1;
                break;
            case 'b':
            case 'e':
            case 'h':
            case 'k':
            case 'n':
            case 'q':
            case 'u':
            case 'x':
                stroke += 2;
                break;
            case 'c':
            case 'f':
            case 'i':
            case 'l':
            case 'o':
            case 'r':
            case 'v':
            case 'y':
                stroke += 3;
                break;
            case 's':
            case 'z':
                stroke += 4;
                break;
            default :
                return 0;
            }
        }
        if(i > 0)
        {
            printf("Case #%d: %d\n",i,stroke);
        }
        stroke = 0;
        i++;
        if(i == n+1)
        {
            return 0;
        }
    }
    return 0;
}
