#include <bits/stdc++.h>
using namespace std;
int main()
{
    double bizhi,l,r,x,y,k,i,j;
    bool flag = true;
    cin >> l >> r >> x >> y >> k;
    bizhi = 0;
    for(i=l;i<=r;i++)
    {
        for(j=x;j<=y;j++)
        {
            bizhi = i*1.00000000/j;
            if(bizhi<k)
                break;
            else if(bizhi == k)
            {
                cout << "YES";
                return 0;
                break;
            }
        }
    }
    cout << "NO";
    return 0;
}
