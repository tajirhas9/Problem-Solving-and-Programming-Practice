#include <iostream>
using namespace std;
int main()
{
    unsigned long long int n,a[100000] = {0},i,b,c=0,x,k=0,m=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> b;
        if(i==0)
            x = b;
        if(b >= x)
        {
            a[k]++;
            x = b;
        }
        else
        {
            x = b;
            k++;
            a[k]=1;
        }
    }
    for(i=0;i<=k;i++)
    {
        if(m < a[i])
            m = a[i];
    }
    cout << m;
    return 0;
}
