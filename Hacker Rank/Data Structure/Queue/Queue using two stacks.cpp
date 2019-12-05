#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,y;
    queue<int > a;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x == 1)
        {
            cin >> y;
            a.push(y);
        }
        else if(x == 2)
        {
            a.pop();
        }
        else
        {
            cout << a.front() << endl;
        }
    }
    return 0;
}
