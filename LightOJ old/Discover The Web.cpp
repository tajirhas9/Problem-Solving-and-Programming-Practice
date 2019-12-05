#include <iostream>
#include <stack>
using namespace std;
int main()
{
    std::stack<std::string> b,f;
    int t,i;
    //b.push("http://www.lightoj.com/");
    cin >> t;
    string s,web;
    for(i=1;i<=t;i++)
    {
        cout << "Case " << i << ":" << endl;
        while(1)
        {
            cin >> s;
            if(s == "VISIT")
            {
                if(web != "")
                {
                    b.push(web);
                }
                else
                {
                    b.push("http://www.lightoj.com/");
                }
                while(!f.empty())
                    f.pop();
                cin >> web;
                cout << web << endl;
            }
            else if(s == "BACK")
            {
                if(b.empty())
                    cout << "Ignored" << endl;
                else
                {
                    if(web != "")
                    {
                        f.push(web);
                    }
                    cout << b.top() << endl;
                    web = b.top();
                    b.pop();
                }
            }
            else if(s == "FORWARD")
            {
                if(f.empty())
                    cout << "Ignored" << endl;
                else
                {
                    b.push(web);
                    cout << f.top() << endl;
                    web = f.top();
                    f.pop();
                }
            }
            else if(s  == "QUIT")
                break;
        }
        while(!f.empty())
            f.pop();
        while(!b.empty())
            b.pop();
        web = "";
    }
    return 0;
}
