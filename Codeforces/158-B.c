/*
*
*Wrong Answer on test case 52
*8
*1 1 2 1 1 1 3 2
*Output : 4
*Answer : 3
*
*/
#include <stdio.h>
int main()
{
    int a[110000],n,countTaxi=0,countMan=0,i,j,countTeam=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i++)
    {
        if(a[i] != 0)
        {
            countMan = a[i];
            if(a[i] < 4)
            {
                printf("Team no %d is sitting with ",i+1);
                j=0;
                while(countMan < 4)
                {
                    if(j==i || a[j] == 0)
                    {
                        j++;
                        continue;
                    }
                    else
                    {
                        if(countMan+a[j] <= 4)
                        {
                            countMan += a[j];
                            a[j] = 0;
                            countTeam++;
                            printf("Team no %d, ",j+1);
                        }
                    }
                    j++;
                    if(j >= n)
                        break;
                }
                countTaxi++;
                countTeam++;
                printf("\nTaxi no : %d gone\n",countTaxi);
                a[i] = 0;
            }
            else
            {
                countTaxi++;
                countTeam++;
                printf("Team no %d is in Taxi no %d\nTaxi no : %d gone\n",i+1,countTaxi,countTaxi);
                a[i] = 0;
            }
        }
        if(countTeam == n)
            break;
    }
    printf("%d",countTaxi);
    return 0;
}
