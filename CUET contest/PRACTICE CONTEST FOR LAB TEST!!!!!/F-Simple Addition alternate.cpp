#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    unsigned long long int p,q,i,sum=0,s,t;
    while(1)
    {
        cin >> p >> q;
        if(p == -1 && q == -1)
            return 0;
        sum = 45*(q/10)-45*((p-1)/10);
        s = ((p/10)*10)+1;
        for(i=s;i<p;i++)
        {
            sum -= i%10;
        }
        s = ((q/10)*10)+9;
        for(i=s;i>q;i--)
        {
            sum -= i%10;
        }
        s = s = ((p/10)*10)+10;
        for(i=s;i<q;i+=10)
        {
            sum += i/10;
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}
