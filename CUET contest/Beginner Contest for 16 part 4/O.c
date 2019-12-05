#include <stdio.h>
#include <string.h>
int main()
{
    char A[3000][10],B[3000][10],s[30000],output[3000],sub[20];
    int n,m,i,j,k,l,x;
    scanf("%d %d",&n,&m);
    for(i=0; i< m; i++)
    {
        scanf("%s %s",A[i],B[i]);
    }
    getchar();
    gets(s);
    j=0;
    k=0;
    while(j < strlen(s))
    {
        while(s[j] != ' ')
        {
            sub[k] = s[j];
            j++;
            k++;
        }
        l=0;
        for(l=0;l<3000;l++)
        {
            for(x=0;x<10;x++)
            {
                if((strcmp(sub,A[l])) == 0)
                {
                    puts(A[l]);
                    break;
                }
            }
        }
        l--;

        if((strcmp(A[l],B[l])) == 0 || (strcmp(A[l],B[l])) > 0)
            strcat(output,A[l]);
        else if((strcmp(A[l],B[l])) < 0)
            strcat(output,B[l]);
            puts(output);
        k=0;
    }
    return 0;
}
