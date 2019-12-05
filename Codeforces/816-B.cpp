#include <bits/stdc++.h>
using namespace std;
int main()
{
    static long long int low[200000],high[200000];
    long long int i,n,k,q,j,qLow,qHigh,c=0;
    cin >> n >> k >> q;
    for(i=0;i<n;i++)
    {
        cin >> low[i] >> high[i];
    }
    for(i=0;i<q;i++)
    {
        cin >> qLow >> qHigh;
        while(qLow <= qHigh)
        {
            for(j=0;j<n;j++)
            {
                if(qLow >= low[j] && qLow <= high[j])
                {
                    c++;
                }
            }
            qLow++;
        }
        cout << c << endl;
        c=0;
    }
    return 0;
}
