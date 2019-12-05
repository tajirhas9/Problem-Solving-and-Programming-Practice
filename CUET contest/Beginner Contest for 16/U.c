#include <stdio.h>

int main()
{
    int n,i,a,b,c;
    scanf("%d",&n);
    if(n >= 2 && n <= 20)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(((a+b) > c))
            {
                printf("OK\n");
            }
            else
            {
                printf("Wrong!!\n");
            }
        }
    }
    return 0;
}
