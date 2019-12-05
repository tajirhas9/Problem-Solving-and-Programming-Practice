#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    stack<int > a,b,temp;
    int i,commands,s_queue,psuedo_size=0,x,n,j;
    string s;
    cin >> n;
    for(j=1;j<=n;j++)
    {
        cin >> s_queue >> commands;
        cout << "Case " << j << ":" << endl;
        for(i=1;i<=commands;i++)
        {
            cin >> s;
            if(s[1] == 'u')
            {
                if(psuedo_size >= s_queue)
                {
                    cin >> x;
                    cout << "The queue is full" << endl;
                }
                else
                {
                    if(s[4] == 'L')
                    {
                        cin >> x;
                        a.push(x);
                        psuedo_size++;
                        cout << "Pushed in left: " << x << endl;
                    }
                    else if(s[4] == 'R')
                    {
                        cin >> x;
                        b.push(x);
                        psuedo_size++;
                        cout << "Pushed in right: " << x << endl;
                    }
                }
            }
            else if(s[1] == 'o')
            {
                if(psuedo_size == 0)
                {
                    cout << "The queue is empty" << endl;
                }
                else
                {
                    if(s[3] == 'L')
                    {
                        if(a.empty())
                        {
                            while(!b.empty())
                            {
                                temp.push(b.top());
                                b.pop();
                            }
                            cout << "Popped from left: " << temp.top() << endl;
                            temp.pop();
                            psuedo_size--;
                            while(!temp.empty())
                            {
                                b.push(temp.top());
                                temp.pop();
                            }
                        }
                        else
                        {
                            cout << "Popped from left: " << a.top() << endl;
                            a.pop();
                            psuedo_size--;
                        }
                    }
                    else if(s[3] == 'R')
                    {
                        if(b.empty())
                        {
                            while(!a.empty())
                            {
                                temp.push(a.top());
                                a.pop();
                            }
                            cout << "Popped from right: " << temp.top() << endl;
                            temp.pop();
                            psuedo_size--;
                            while(!temp.empty())
                            {
                                a.push(temp.top());
                                temp.pop();
                            }
                        }
                        else
                        {
                            cout << "Popped from right: " << b.top() << endl;
                            b.pop();
                            psuedo_size--;
                        }
                    }
                }
            }
        }
        while(!a.empty())
            a.pop();
        while(!b.empty())
            b.pop();
        while(!temp.empty())
            temp.pop();
        psuedo_size = 0;
    }
    return 0;
}
