#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    queue<char> q;
    q.top() = 'x';
    int n,man,s=1,l=1,p=1,r=1,h=1,i;
    cin >> n;
    for(i=1;i=<n;i+=5)
    {
        s *= 2;
        l *= 2;
        p *= 2;
        r *= 2;
        h *= 2;
    }
    for(i=1;i<=s;i++)
    {
        q.push('s');
    }
    for(i=1;i<=l;i++)
    {
        q.push('l');
    }
    for(i=1;i<=p;i++)
    {
        q.push('p');
    }
    for(i=1;i<=r;i++)
    {
        q.push('r');
    }
    for(i=1;i<=h;i++)
    {
        q.push('h');
    }
    for(i=1;i<n;i++)
        q.pop();
    switch(q.top())
    {
    case 's':
        cout << "Sheldon" << endl;
        break;
    case 'l':
        cout << "Leonard" << endl;
        break;
    case 'p':
        cout << "Penny" << endl;
        break;
    case 'r':
        cout << "Rajesh" << endl;
        break;
    case 'h':
        cout << "Howard" << endl;
        break;

    }
    return 0;
}
