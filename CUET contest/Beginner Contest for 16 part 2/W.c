#include <stdio.h>
int main()
{
    int n,m,z;
    int i,count=0;
    scanf("%d %d %d",&n,&m,&z);
    for(i = 0; i <= z; i += n)
    {
        if(i % m == 0)
        {
            count++;
        }
    }
    count -= 1;
    printf("%d",count);
    return 0;
}
