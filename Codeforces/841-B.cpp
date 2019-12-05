#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
unsigned long long int i,sum=0,n,a[2000000],b[2000000];
int main()
{
    cin >> n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    if(sum%2 != 0 || (sum-a[n-1])%2 != 0 || (sum-a[0])%2 != 0)
    {
        cout <<  "First" << endl;
        return 0;
    }
    else
    {
        cout << "Second" << endl;
    }
    return 0;
}
