#include <iostream>
using namespace std;
int f_91(int n);
int main()
{
    unsigned long long int n,x;
    while(1)
    {
        cin >> n;
        if(n==0)
            return 0;
        x = f_91(n);
        cout << "f91("<<n<<") = "<<x<<"\n";
    }
    return 0;
}
int f_91(int n)
{
    int x;
    if(n >= 101)
        return (n-10);
    else
    {
        x = f_91(f_91(n+11));
        return x;
    }
}
