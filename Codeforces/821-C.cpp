#include <bits/stdc++.h>
#include <stack>
using namespace std;
stack <unsigned long long int> a;
unsigned long long int p[4000000];
int n,i,j,k,l,x,c=0;
int flag=0;
int main()
{
    string s;
    cin >> n;
    for(i=1; i<=2*n; i++)
    {
        cin >> s;
        if(s[0] == 'a')
        {
            cin >> x;
            if(a.size() != 0 && x > a.top())
            {
                flag = 1;
            }
            a.push(x);
        }
        else if(s[0] == 'r')
        {
            if(flag == 1)
            {
                j=0;
                while(a.size() != 0)
                {
                    p[j] = a.top();
                    a.pop();
                    j++;
                }
                for(k=0; k<j; k++)
                {
                    for(l=k+1; l<j; l++)
                    {
                        if(p[k] < p[l])
                            swap(p[k],p[l]);
                    }
                }
                for(k=0; k<j; k++)
                {
                    a.push(p[k]);
                }
                a.pop();
                flag = 0;
                c++;
            }
            else
            {
                if(a.size() != 0)
                    a.pop();
            }
        }
    }
    cout << c << endl;
    return 0;
}
