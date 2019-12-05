#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    double area,m,b,x,y,i,j,c=0,x1,y1;
    cin >> m >> b;
    x=0;
    y = -(x/m)+b;
    area = (x*y);
    for(x=0;x<(m*b);x++)
    {
        y = -(x/m)+b;
        if(x*y >= (int)area)
        {
            area = x*y;
            x1 = x;
            y1 = y;
        }
    }
    for(i=0;i<=(int)x1;i++)
    {
        for(j=0;j<=(int)y1;j++)
        {
            c += i+j;
        }
    }
    cout << c << endl;
    return 0;
}
