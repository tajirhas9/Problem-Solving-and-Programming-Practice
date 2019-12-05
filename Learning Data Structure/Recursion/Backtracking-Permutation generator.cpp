#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int c=0;
int swaping(char *x,char *y);
int permutation(char a[],int l,int r);
int call();
int main()
{
    char a[100000];
    int n,i,j,common=0,type=0;
    gets(a);
    n = strlen(a);
    permutation(a,0,n-1);
    printf("%d\n",call());
    return 0;
}
int swapping(char *x,char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int permutation(char a[],int l,int r)
{
    int i,j,k;
    if(l == r)
    {
        printf("%s\n",a);
        call();
    }
    for(i=l; i<=r; i++)
    {
        for(j=l; j<=r; j++)
        {
            for(k=j+1; k<=r; k++)
            {
                if(a[k] <a[j])
                    swap(a[k],a[j]);
            }
        }
        if(a[i] == a[i+1])
            continue;
        swapping(&a[l],&a[i]);
        permutation(a,l+1,r);
        swapping(&a[l],&a[i]); //backtrack
    }
}
int call()
{
    c++;
    return c-1;
}
