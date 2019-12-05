#include <stdio.h>
int main()
{
    int m,n,i,area;
    scanf("%d %d",&m,&n);
    area = m*n;
    while(area%2 != 0)
    {
        area--;
    }
    printf("%d",area/2);
    return 0;
}
