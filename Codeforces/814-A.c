#include <stdio.h>
int main()
{
    int a[300],b[300],zero[300],i,numA,numB,max=0,count=1,j,allEqual=1;
    for(i=0;i<300;i++)
        zero[i] = 0;
    scanf("%d %d",&numA,&numB);
    for(i=0;i<numA;i++)
    {
        scanf("%d",&a[i]);
        if(a[i] == 0)
            zero[i] = 1;
    }
    for(i=0;i<numB;i++)
        scanf("%d",&b[i]);
    while(count<=numB)
    {
        for(i=0;i<numB;i++)
        {
            if(b[max] < b[i])
                max = i;
        }
        for(i=0;i<numA;i++)
        {
            if(a[i]  == 0)
            {
                a[i] = b[max];
                break;
            }
        }
        b[max] = 0;
        max = 0;
        count++;
    }
    /*for(i=0;i<numA;i++)
    {
        printf("%d ",a[i]);
    }*/
    for(i=0;i<numA;i++)
    {
        for(j=1;j<numA;j++)
        {
            if(a[j] != a[i])
            {
                allEqual = 0;
            }
        }
    }
    for(i=0;i<(numA-1);i++)
    {
        if(a[i] > a[i+1])
            break;
    }
    if(i == (numA-1) && allEqual == 0)
        printf("No");
    else
        printf("Yes");
    return 0;
}
