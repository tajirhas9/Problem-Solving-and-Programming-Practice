#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> man,circle;
    int track=0,time=0,temp=0,check,box=1;
    int t,n,m,i,j;
    cin >> t;
    for(i=1; i<=t; i++)
    {
        cin >> m >> n;
        for(j=1; j<=m; j++)
            man.push(j);
        circle.push(man.front());
        man.pop();
        track++;
        time += 5;
        while(man.size() < m)
        {
            if(circle.size() != 0)
            {
                temp = circle.front();
                circle.pop();
            }
            if(man.size() != 0)
            {
                circle.push(man.front());
                man.pop();
            }
            if(temp != 0)
                man.push(temp);

        }
    }
    return 0;
}
