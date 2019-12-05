#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    stack<int> r;
    char s[100000];
    int l,u,v,i;
    gets(s);
    l = strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i] == ' ')
            continue;
        if(s[i] >= '0' && s[i] <='9')
        {
            r.push(s[i]-'0');
        }
        else if(r.size() >= 2 && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'))
        {
            if(s[i] == '+')
            {
                u = r.top();
                r.pop();
                v = r.top();
                r.pop();
                r.push(u+v);
            }
            else if(s[i] == '-')
            {
                u = r.top();
                r.pop();
                v = r.top();
                r.pop();
                r.push(v-u);
            }
            else if(s[i] == '*')
            {
                u = r.top();
                r.pop();
                v = r.top();
                r.pop();
                r.push(u*v);
            }
            else if(s[i] == '/')
            {
                u = r.top();
                r.pop();
                v = r.top();
                r.pop();
                r.push(v/u);
            }
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
    if(r.size() == 1)
    {
        cout << r.top() << endl;
        r.pop();
    }
    else
        cout << "Invalid input" << endl;
    while(!r.empty())
        r.pop();
    return 0;
}
