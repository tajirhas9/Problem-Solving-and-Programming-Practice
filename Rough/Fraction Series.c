#include <stdio.h>
int main()
{
    double sum=0,numerator,denominator;
    int i,j,step,terms;
    scanf("%d",&terms);
    for(i=1,j=2,step=1;step<=terms;i++,j+=2,step++)
    {
        numerator = i+(i+1);
        denominator = j*(j+2);
        sum += numerator/denominator;
    }
    printf("%lf",sum);
    return 0;
}
