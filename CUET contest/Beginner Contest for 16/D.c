#include <stdio.h>
int main()
{
    int v,t;
    int s;
    while(scanf("%d %d",&v,&t) == 2)
    {
        s = v*t*2;
        printf("%d\n",s);
    }
    return 0;
}
