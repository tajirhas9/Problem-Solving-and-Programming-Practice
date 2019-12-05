#include <stdio.h>
#include <string.h>
int main()
{
    char s[30];
    int palindrome=1,mirror=1,l,i,j;
    while(scanf("%s",s) == 1)
    {
        l = strlen(s);
        if(l%2!=0)
        {
            for(i=0,j=(l-1);i<((l/2)+1);i++,j--)
            {
                if(s[i] != s[j])
                {
                    palindrome = 0;
                    break;
                }
            }
            for(i=0,j=(l-1);i<((l/2)+1);i++,j--)
            {
                if(s[i] == 'A' || s[i] == 'E' || s[i] == 'H' || s[i] == 'I' || s[i] == 'J' || s[i] == 'L' || s[i] == 'M' || s[i] == 'O' || s[i] == 'S' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' || s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'Z' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '8')
                {
                    switch(s[i])
                    {
                    case 'A' :
                    case 'H' :
                    case 'I' :
                    case 'M' :
                    case 'O' :
                    case 'T' :
                    case 'U' :
                    case 'V' :
                    case 'W' :
                    case 'X' :
                    case 'Y' :
                    case '1' :
                    case '8' :
                        if(s[i] != s[j])
                            mirror=0;
                        break;
                    case 'E' :
                        if(s[j] != '3')
                            mirror=0;
                        break;
                    case 'J' :
                        if(s[j] != 'L')
                            mirror=0;
                        break;
                    case 'L' :
                        if(s[j] != 'J')
                            mirror=0;
                        break;
                    case 'S' :
                        if(s[j] != '2')
                            mirror=0;
                        break;
                    case 'Z' :
                        if(s[j] != '5')
                            mirror=0;
                        break;
                    case '2' :
                        if(s[j] != 'S')
                            mirror=0;
                        break;
                    case '3' :
                        if(s[j] != 'E')
                            mirror=0;
                        break;
                    case '5' :
                        if(s[j] != 'Z')
                            mirror=0;
                        break;
                    }
                }
                else
                    mirror=0;
            }
        }
        else
        {
            palindrome = 0;
            mirror = 0;
        }
        if(palindrome == 0 && mirror == 0)
            printf("%s -- is not a palindrome.\n",s);
        else if(palindrome == 1 && mirror == 0)
            printf("%s -- is a regular palindrome.\n",s);
        else if(palindrome == 0 && mirror == 1)
            printf("%s -- is a mirrored string.\n",s);
        else
            printf("%s -- is a mirrored palindrome.\n",s);
            palindrome = 1;
            mirror = 1;
    }
    return 0;
}
