#include <bits/stdc++.h>
using namespace std;
int main()
{
    int levels,p[150],q[150],l[150] = {0},a,b;
    int i;
    cin >> levels;
    cin >> a;
    for(i=1;i<=a;i++)
    {
        cin >> p[i];
        if(l[p[i]] == 0)
            l[p[i]]++;
    }
    cin >> b;
    for(i=1;i<=b;i++)
    {
        cin >> p[i];
        if(l[p[i]] == 0)
            l[p[i]]++;
    }
    for(i=1;i<=levels;i++)
    {
        if(l[i] == 0)
        {
            cout << "Oh, my keyboard!" << endl;
            return 0;
        }
    }
    cout << "I become the guy." << endl;
    return 0;
}
