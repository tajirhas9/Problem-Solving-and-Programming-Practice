#include <iostream>
#include <queue>
using namespace std;
queue<int > a;
int main()
{
    int n,x,i;
    cin >> n;
    for(i = 1; i <= n;i++)
    {
        cin >> x;
        a.push(x);
    }
    for(i=1;i<=n;i++)
    {
        cout << a.front() << " ";
        a.pop();
    }
    return 0;
}
