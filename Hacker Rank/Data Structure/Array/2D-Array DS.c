#include <stdio.h>
int main()
{
    int i,j,k=0,a[6][6],b[16];
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            b[k] = a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+1]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
            k++;
        }
    }
    for(i=0;i<16;i++)
    {
        for(j=i+1;j<16;j++)
        {
            if(b[i]<b[j])
            {
                b[i] = b[i]+b[j];
                b[j] = b[i]-b[j];
                b[i] = b[i]-b[j];
            }
        }
    }
    printf("%d",b[0]);
    return 0;
}
