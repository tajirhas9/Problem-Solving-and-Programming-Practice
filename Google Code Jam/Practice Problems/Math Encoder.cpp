#include <iostream>
using namespace std;
int main()
{
    int a[10000],i,j,sum=0,t,k,x,n;
    cin >> t;
    for(x=1; x<=t; x++)
    {
        cin >> n;
        for(i=0; i<n; i++)
            cin >> a[i];
        for(k=1; k<=n; k++)
        {
            for(i=0; i<(n-k); i++)
            {
                for(l=1; l<=(j-i-1); l++)
                {
                    for(j=i; j<n; j+=k)
                    {
                        sum += a[j]-a[i];
                        cout << k << "\t" << a[j] << "-" << a[i] << "=" << sum << endl;
                    }
                }
            }
        }
        cout << "Case #" << x << ": " << sum << endl;
    }
    return 0;
}
