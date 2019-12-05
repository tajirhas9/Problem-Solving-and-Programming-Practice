#include <stdio.h>
int main()
{
    int i,j;
    long long int size,rotations,firstIndex,a[110000];
    scanf("%lld %lld",&size,&rotations);
    for(i=0;i<size;i++)
        scanf("%lld",&a[i]);
    rotations %= size;
    /*for(i=1;i<=rotations;i++)
    {
        firstIndex = a[0];
        for(j=0;j<(size-1);j++)
            a[j] = a[j+1];
        a[size-1] = firstIndex;
    }*/
    for(i=(0+rotations);i<size;i++)
        printf("%lld ",a[i]);
    for(i=0;i<(0+rotations);i++)
        printf("%lld ",a[i]);
    return 0;
}
