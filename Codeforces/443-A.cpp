#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int l,i,j,x=0;
    char a[1100];
    gets(a);
    l = strlen(a);
    for(i=1;i<l;i+=3,x++)
    {
        if(a[i] >= 'a' && a[i] <= 'z')
        {
            for(j=i+3;j<l;j+=3)
            {
                if(a[i] == a[j] && a[j] >= 'a' && a[j] <= 'z')
                {
                    a[j] = '0';
                    x--;
                }
            }
        }
    }
    if(l==2)
    x=0;
    cout << x;
    return 0;
}
