#include <iostream>
using namespace std;
unsigned long long int addFunc(unsigned long long int n);
int main()
{
    unsigned long long int p,q,i,sum=0;
    while(1)
    {
        cin >> p >> q;
        if(p== -1 && q == -1)
            return 0;
        for(i=p;i<=q;i++)
        {
            sum += addFunc(i);
        }
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}
unsigned long long int addFunc(unsigned long long int n)
{
    if(n%10 > 0)
        return (n%10);
    else if(n==0)
        return 0;
    else
        return addFunc(n/10);
}
