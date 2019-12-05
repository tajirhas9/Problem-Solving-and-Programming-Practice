#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    long long int k,i,sum=0,step=0,l,temp;
    cin >> k >> n;
    l = n.length();
again:
    for(i=0; i<l; i++)
    {
        sum += n[i]-'0';
    }
    if(sum >= k)
    {

        cout << step;
        return 0;
    }
    else
    {
        for(i=(l-1);i>=0;i--)
        {
            temp = ((n[i]-'0')+1);
            if(temp <=9)
            {
                n[i] = n[i]+1;
                break;
            }
            else
            {
                n[i] = (((n[i]-'0')+1)%10)+'0';
            }
        }
        step++;
        sum = 0;
        goto again;
    }
    return 0;
}
