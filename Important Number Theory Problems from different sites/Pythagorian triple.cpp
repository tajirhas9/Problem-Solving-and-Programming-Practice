#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    unsigned long long int a,b,c,n;
    cin >> a;
    if(a%2 != 0)
    {
        b = ((a*a)-1)/2;
        c = b+1;
    }
    else
    {
        n= (a*a)/4;
        b = n-1;
        c=n+1;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}
