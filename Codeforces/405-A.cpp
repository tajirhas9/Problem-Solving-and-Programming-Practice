#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[200],i,j,n;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> a[i];
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j] < a[i])
                swap(a[j],a[i]);
        }
    }
    for(i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
