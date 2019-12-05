#include <stdio.h>
int main()
{
    int c,y,a[5],i,j,r;
    scanf("%d",&y);
    i=0;
    y++;
    c = y;
label :
    while(c>0)
    {
        r = c%10;
        a[i] = r;
        c /= 10;
        i++;
    }
    for(i=0; i<4; i++)
    {
        for(j=i+1; j<4; j++)
        {
            if(a[i] == a[j])
            {
                y++;
                c = y;
                i = 0;
                goto label;
            }
        }
    }
    printf("%d",y);
    return 0;
}
