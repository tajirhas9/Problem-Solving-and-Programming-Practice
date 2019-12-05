#include <stdio.h>
int main()
{
    char s;
    scanf("%c",&s);
    if(s >= 'A' && s <= 'Z')
        printf("Upper Case");
    else if(s >= 'a' && s <= 'z')
        printf("Lower Case");
    else if(s >= '0' && s<= '9')
        printf("Digit");
    else
        printf("I don't know");
    return 0;
}
