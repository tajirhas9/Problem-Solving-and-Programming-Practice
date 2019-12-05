#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int result,a[100010],b[100010],i,j,n,minAPos=0,minBPos=0,minApos2=0,minBpos2=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
         cin >> a[i];
        if(a[minAPos] > a[i])
            minAPos = i;
    }
    for(i=0;i<n;i++)
    {
        cin >> b[i];
        if(b[minBPos] > b[i])
            minBPos = i;
    }
    if(minAPos == minBPos)
    {
        minApos2 = (n-minAPos)+1;
        minBpos2 = (n-minBPos)+1;
        for(i=0;i<n;i++)
        {
            if(i != minAPos && a[i] < a[minApos2])
                minApos2 = i;
        }
        for(i=0;i<n;i++)
        {
            if(i != minBPos && b[i] < b[minBpos2])
                minBpos2 = i;
        }
        ((a[minAPos]+b[minBpos2]) > (a[minApos2]+b[minBPos])) ? result = a[minApos2]+b[minBPos] : result = a[minAPos]+b[minBpos2];

    }
    else
    {
        result = a[minAPos]+b[minBPos];
    }
    cout << result << endl;
    return 0;
}
