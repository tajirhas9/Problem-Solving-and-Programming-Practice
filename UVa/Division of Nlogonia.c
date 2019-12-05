#include <stdio.h>
int main()
{
    int n,i,x,y,x1,y1;
    while((scanf("%d",&n)))
    {
        if(n == 0)
        {
            return 0;
        }
        scanf("%d %d",&x,&y);
        if(n > 0 && n <= 1000 && x > -10000 && x < 10000 && y > -10000 && y < 10000)
        {
            for(i = 1; i <= n; i++)
            {
                scanf("%d %d",&x1,&y1);
                if(x1 >= -10000 && x1 <= 10000 && y1 >= -10000 && y1 <= 10000)
                {
                    if(x == x1 || y == y1)
                    {
                        printf("divisa\n");
                    }
                    else if(x1 < x && y1 > y)
                    {
                        printf("NO\n");
                    }
                    else if(x1 > x && y1 > y)
                    {
                        printf("NE\n");
                    }
                    else if(x1 < x && y1 < y)
                    {
                        printf("SO\n");
                    }
                    else if(x1 > x && y1 < y)
                    {
                        printf("SE\n");
                    }
                }
            }
        }
    }
    return 0;
}
