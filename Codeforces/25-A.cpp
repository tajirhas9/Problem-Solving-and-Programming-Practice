#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,even=0,odd=0,n,a[200],c;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]%2==0)
            even++;
        else
            odd++;
    }
    if(even>odd)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]%2 != 0)
            {
                c = i+1;
                break;
            }
        }
    }
    if(even<odd)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]%2 == 0)
            {
                c = i+1;
                break;
            }
        }
    }
    cout << c;
    return 0;
}
