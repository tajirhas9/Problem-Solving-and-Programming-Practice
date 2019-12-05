#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,sum=0;
    char s[13];
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%s",s);
       if(!strcmp(s,"Tetrahedron"))
       {
           sum += 4;
       }
       else if(!strcmp(s,"Cube"))
       {
           sum += 6;
       }
       else if(!strcmp(s,"Octahedron"))
       {
           sum += 8;
       }
       else if(!strcmp(s,"Dodecahedron"))
       {
           sum += 12;
       }
       else if(!strcmp(s,"Icosahedron"))
       {
           sum += 20;
       }
       else
       {
           return 0;
       }
    }
    printf("%d",sum);
    return 0;
}

