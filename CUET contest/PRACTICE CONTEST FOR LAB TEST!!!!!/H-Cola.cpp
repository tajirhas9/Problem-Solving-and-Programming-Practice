#include <iostream>
#include <stdio.h>
using namespace std;
int cola(int n);
int main()
{
    int n,sum=0;
    while((scanf("%d",&n)) == 1)
    {
        cout << (n+n/2) << endl;
    }
    return 0;
}
