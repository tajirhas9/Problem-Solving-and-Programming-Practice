//Have errors
#include <stdio.h>
int main()
{
    int a,b,stan,ollie;
    while(scanf("%d %d",&a,&b) == 2)
    {
        if(a  == 0 && b == 0 ) break;
        while( a != 1 || b != 1)
        {
            if(a == 1 || b == 1) break;
            if(a > b)
            {
                if(a%b == 0 || a <= 1)
                {
                    printf("Stan wins\n");
                    break;
                }
                else  if(b%a == 0 || b <= 1)
                {
                    printf("Ollie wins\n");
                    break;
                }
                a = a%b;
                printf("%d %d\n",a,b);
            }
            else if(b > a)
            {
                if( a%b == 0 || a <= 1)
                {
                    printf("Ollie wins\n");
                    break;
                }
                else if(b%a == 0 || b <= 1)
                {
                    printf("Stan wins\n");
                    break;
                }
                b = b%a;
                printf("%d %d\n",a,b);
            }
        }
    }
    return 0;
}
