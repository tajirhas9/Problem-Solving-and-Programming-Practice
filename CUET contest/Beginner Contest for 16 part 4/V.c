#include <stdio.h>
#include <string.h>
int main()
{
    char team[100],teamA[15],teamB[15];
    int n,i,countA=0,countB=0;
    scanf("%d",&n);
    getchar();
    for(i=0; i<n; i++)
    {
        gets(team);
        if(i==0)
            strcpy(teamA,team);
        if((strcmp(team,teamA)) != 0)
            strcpy(teamB,team);
        if((strcmp(team,teamA)) == 0)
        {
            countA++;
        }
        else
        {
            countB++;
        }
    }
    if(countA > countB)
        printf("%s",teamA);
    else
        printf("%s",teamB);
    return 0;
}
