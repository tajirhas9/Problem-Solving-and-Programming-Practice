#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int main()
{
    stack<char> b;
    int l,n,i,j,f=0;
    char s[200];
    scanf("%d",&n);
    getchar();
    for(i=1;i<=n;i++)
    {
        gets(s);
        l = strlen(s);
        for(j=0;j<l;j++)
        {
            if(s[j] == '(' || s[j] == '[')
                b.push(s[j]);
            else
            {
                if(b.empty() || (b.top() == '(' && s[j] != ')'))
                {
                    f = 1;
                    break;
                }
                else if(b.empty() || (b.top() == '[' && s[j] != ']'))
                {
                    f=1;
                    break;
                }
                else
                    b.pop();
            }
        }
        (b.empty() && f == 0) ? cout << "Yes" << endl : cout << "No" << endl;
        while(!b.empty())
            b.pop();
            f=0;
    }

    return 0;
}
