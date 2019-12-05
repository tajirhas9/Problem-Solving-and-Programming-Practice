#include <stdio.h>
int main()
{
    int n,lucky=0,r;
    scanf("%d",&n);
    if(n%4==0 || n%7==0)
        lucky = 1;
    else
    {
        while(n>0)
        {
            r = n%10;
            n /= 10;
            if(r == 4 || r == 7)
            {
                lucky = 1;
                continue;
            }
            else
            {
                lucky = 0;
                break;
            }
        }
    }
    if(lucky==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
