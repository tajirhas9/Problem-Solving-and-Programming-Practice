#include <bits/stdc++.h>
using namespace std;
int find_div(int n);
int  main()
{
    int i,j,k=1,divisors[2000],sorted[2000],t,n;
    for(i=1;i<=1000;i++)
        divisors[i] = find_div(i);
    i=1;
    while(k<=1000)
    {
        if(divisors[i] != -1)
            sorted[k] = i;
        else
        {
            i++;
            continue;
        }
        for(j=1;j<=1000;j++)
        {
            if(i == j || divisors[j] == -1) continue;
            if(divisors[j] < divisors[sorted[k]])
                sorted[k] = j;
            else if(divisors[j] == divisors[sorted[k]] && j>sorted[k])
                sorted[k] = j;
        }
        divisors[sorted[k]] = -1;
        k++;
        i=1;
    }
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> n;
        cout << "Case " << i << ": " << sorted[n] << endl;
    }
    return 0;
}
int find_div(int n)
{
    int i,t=1;
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
            t++;
    }
    return t;
}
