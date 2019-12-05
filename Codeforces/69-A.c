#include <stdio.h>
int main()
{
    int n,sumA=0,sumB=0,sumC=0,i,a,b,c;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        sumA += a;
        sumB += b;
        sumC += c;
		
    }
    if(sumA == 0 && sumB == 0 && sumC == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
