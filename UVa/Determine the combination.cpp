#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
using namespace std;
int permute(char a[],int l,int n);
int level=0;
int main()
{
    char s[100],a[100];
    int r,l,i,j,k=0,m=1;
    while((scanf("%s",s)) == 1)
    {
        scanf("%d",&r);
        l = strlen(s);
        for(i=0;i<l;i++)
        {
            for(j=i+k;j<l;j++,k++)
            {
                a[j] = s[j];
                if(k == r-1)
                {
                    permute(a,0,r);
                    m++;
                    k=m;
                    j = i+k;
                }
                k = 1;
                m = 1;
            }
        }
    }
    return 0;
}
int permute(char a[],int l,int n)
{
    int i,j,k;
    if(l==n)
        printf("%s\n",a);
    for(i=l;i<n;i++)
    {
        for(j=l;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(a[k] < a[j])
                    swap(a[k],a[j]);
            }
        }
        if(a[i] == a[i+1])
            continue;
        swap(a[i],a[l]);
        level++;
        permute(a,l+1,n);
        swap(a[i],a[l]);
    }
}
