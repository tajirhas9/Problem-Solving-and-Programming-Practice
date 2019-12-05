#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
    double f1=1,f2=1,area=0,temp;
    int i=1,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        area += (f1*f1)-((3.141593*f1*f1)/4);
        while(++i <= n)
        {
            temp = f1;
            f1 = f2;
            area += (f2*f2)-((3.141593*f2*f2)/4);
            f2 = temp+f2;
        }
        printf("%0.2lf\n",area);
        area = 0;
        f1 = 1;
        f2 = 1;
        i = 1;
    }
    return 0;
}
