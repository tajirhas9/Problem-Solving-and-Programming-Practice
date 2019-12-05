#include <iostream>
#include <stack>
using namespace std;
stack <char> brackets;
int main()
{
    int i,l;
    string s;
    cin >> s;
    l = s.length();
    for(i=0;i<l;i++)
    {
        if(s[i] == '(' || s[i]  == '{' || s[i] == '[')
            brackets.push(s[i]);
        else if(s[i]  == ')' || s[i] == '}'  || s[i] == ']')
        {
            if(brackets.top() == '(' && s[i] != ')')
            {
                cout << "The bracket sequence is imbalanced\n";
                return 0;
            }
            else if(brackets.top() == '{' && s[i] != '}')
            {
                cout << "The bracket sequence is imbalanced\n";
                return 0;
            }
            else if(brackets.top() == '[' && s[i] != ']')
            {
                cout << "The bracket sequence is imbalanced\n";
                return 0;
            }
            else
            {
                brackets.pop();
            }
        }
    }
    brackets.empty() ? cout << "The bracket sequence is balanced\n"  : cout << "The bracket sequence is imbalanced\n";;
    return 0;
}
