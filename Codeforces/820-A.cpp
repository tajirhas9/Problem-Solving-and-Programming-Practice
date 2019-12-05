#include <bits/stdc++.h>
using namespace std;
int main()
{
    int day=1,c,v,v1,a,i,pages=0,x,l;
    cin >> c >> v >> v1 >> a >> l;
    for(i=0;pages < c;i++)
    {
        x = v+i*a;
        if(x > v1)
            x = v1;
        pages += x;
        if(pages >= c)
            break;
        pages -= l;
        day++;
    }
    cout << day;
    return 0;
}
