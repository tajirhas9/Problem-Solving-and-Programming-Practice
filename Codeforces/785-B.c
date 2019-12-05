#include <stdio.h>
#include <stdlib.h>
void main(void)
{
    int chess[200000];
    int prog[200000];
    int n,m,i,j,counter=0;
    scanf("%d",&n);
    if(n >= 1 && n <= 200000)
    {
        for(i = 0; i < 2*n; i+=2)
        {
            scanf("%d",&chess[i]);
            scanf("%d",&chess[i+1]);
            if(chess[i] > chess[i+1] )
            {
                return 0;
            }
        }
        scanf("%d",&m);
        if(m >= 1 && m <= 200000)
        {
            for(i = 0; i < 2*m; i+=2)
            {
                scanf("%d",&prog[i]);
                scanf("%d",&prog[i+1]);
                if(prog[i] > prog[i+1])
                {
                    return 0;
                }
            }
        }
    }
    for(i = 1; i <= 2*n; i+=2)
    {
        for(j = 0; j < 2*m; j += 2)
        {
            if((prog[j] > chess[i]) && (counter < prog[j] - chess[i]))
            {
                counter = prog[j] - chess[i];
            }
        }
    }
    printf("%d",counter);


}
