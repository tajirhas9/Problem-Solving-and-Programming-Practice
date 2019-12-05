#include <stdio.h>
int main()
{
    int before[1000],after[1000];
    int n,i,rated=0,mayb=1,j;
    int serial;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&before[i],&after[i]);
        if(before[i] != after[i])
            rated = 1;
    }
    if(rated==1)
        printf("rated");
    else
    {
        for(i=0; i<(n-1); i++)
        {
            if(before[i] >= before[i+1])
                continue;
            else
                mayb=0;
        }
        if(mayb==1)
            printf("maybe");
        else
            printf("unrated");
    }
    return 0;
}
