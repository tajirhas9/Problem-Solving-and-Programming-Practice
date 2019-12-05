#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
int main()
{
    stack<char > b;
    int t,l,i,flag=0;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        l = s.length();
        for(i=0;i<l;i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                b.push(s[i]);
            else if(!b.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
            {
                if(b.top() == '(' && s[i] != ')')
                {
                    flag = 1;
                }
                else if(b.top() == '{' && s[i] != '}')
                {
                    flag = 1;
                }
                else if(b.top() == '[' && s[i] != ']')
                {
                    flag = 1;
                }
                b.pop();
            }
            else if(b.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
                flag = 1;
            else
                b.pop();
        }
        (flag == 0 && b.empty()) ? cout << "YES" << endl : cout << "NO" << endl;
        flag = 0;
        while(!b.empty())
            b.pop();
    }
    return 0;
}
