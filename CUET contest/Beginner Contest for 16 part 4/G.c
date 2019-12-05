#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[2000];
    int i,l;
    gets(s);
    l = strlen(s);
    s[0] = toupper(s[0]);
    puts(s);
    return 0;
}
