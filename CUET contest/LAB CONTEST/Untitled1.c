#include <stdio.h>
int main()
{
    long long int e,t,n,m,a[200],i,j,x,y,k,temp,b[200],flag = 0,h;
    char s;
    scanf("%lld",&t);
    for(e=1;e<=t;e++)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
        }
        getchar();
        for(h=1; h<=m; h++)
        {
            scanf("%c",&s);
            if(s == 'S')
            {
                scanf("%lld",&x);
                for(j=0; j<n; j++)
                {
                    a[j] += x;
                }
            }
            else if(s == 'M')
            {
                scanf("%lld",&x);
                for(j=0; j<n; j++)
                    a[j] *= x;
            }
            else if(s == 'D')
            {
                scanf("%lld",&x);
                for(j=0; j<n; j++)
                    a[j] /= x;
            }
            else if(s == 'P')
            {
                scanf("%lld %lld",&x,&y);
                temp = a[x];
                a[x] = a[y];
                a[y] = temp;
            }
            else if(s == 'R')
            {
                for(j=0,k=(n-1); j<n; j++,k--)
                {
                    b[j] = a[k];
                }
                flag = 1;
            }
            getchar();
        }
        printf("Case %lld:\n",e);
        if(flag == 0)
        {
            for(j=0; j<n; j++)
                printf("%lld ",a[j]);
        }
        else
        {
            for(j=0; j<n; j++)
                printf("%lld ",b[j]);
        }
        printf("\n");
        flag = 0;
    }
    return 0;
}
