#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,v;
    double x,y1=0,y2=0,temp;
    cin >> n >> a;
    x = ((n-2)*180)/n;
    y1 = x;
    for(v=(n-2);v > 1;v--)
    {
        y2 = y1;
        y1 = x/((v-1)*(n-2));
        if(abs(y2-a) > abs(y1-a))
        {
            cout << 1 << " " <<(n-1) << " " << v;
            return 0;
        }
    }
    cout << 1 << " " << n << " " << (n-1);
    return 0;
}
