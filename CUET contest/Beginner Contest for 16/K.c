#include <stdio.h>
int main()
{
    int n,i,j,k,temp;
    int num[3];
    scanf("%d",&n);
    if(n < 20)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d %d %d",&num[0],&num[1],&num[2]);
            if((num[0] >= 1000 && num[0] <= 10000) && (num[1] >= 1000 && num[1] <= 10000) && (num[2] >= 1000 && num[2] <= 10000))
            {
                for(j = 0; j < 3; j++)
                {
                    for(k = j+1; k < 3; k++)
                    {
                        if(num[k] < num[j])
                        {
                            temp = num[j];
                            num[j] = num[k];
                            num[k] = temp;
                        }
                    }
                }
                printf("Case %d: %d\n",i,num[1]);
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
