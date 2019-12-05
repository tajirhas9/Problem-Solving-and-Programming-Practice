#include <iostream>
#include <stack>
#include <cstdio>
#include <climits>
using namespace std;
int main()
{
    stack<int > q;
    stack<int > t;
    stack<long long int > ma;
    long long int x,i,n,p;
    ma.push(LLONG_MIN);
    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&p);
        if(p == 1)
        {
            scanf("%lld",&x);
            q.push(x);
            if(ma.top() <= q.top())
                ma.push(q.top());
        }
        else if(p == 2)
        {
            if(q.top() == ma.top())
                ma.pop();
            q.pop();
        }
        else
        {
            /*while(!q.empty())
            {
                if(m < q.top())
                    m = q.top();
                t.push(q.top());
                q.pop();
            }
            while(!t.empty())
            {
                q.push(t.top());
                t.pop();
            }*/
            printf("%lld\n",ma.top());
        }
    }
    return 0;
}
