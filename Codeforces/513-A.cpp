#include <bits/stdc++.h>
using namespace std;
int main()
{
    int c,n1,n2,k1,k2,t=1;
    cin >> n1 >> n2 >> k1 >> k2;
    while(1)
    {
        if(t%2==0)
            n2 -= k2;
        else
            n1 -= k1;
        cout << n1 << " " << n2 << endl;
        if(n1 <= 0)
        {
            c = 1;
            break;
        }
        else if(n2 <= 0)
        {
            c = 2;
            break;
        }
        t++;
    }
    if(c == 1)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}
