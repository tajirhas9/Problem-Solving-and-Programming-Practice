#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifdef tajir
        freopen("input.txt","r",stdin);
    #else
    #endif
    int n,i,a,m=2000000001,l,c=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a < m)
        {
            m = a;
            c = 1;
            l = i;
        }
        else if(a==m)   c++;
    }
    if(c>1) printf("Still Rozdil\n");
    else    printf("%d\n",l);
    return 0;
}
