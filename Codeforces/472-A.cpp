#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
int isPrime(unsigned long long int n)
{
    unsigned long long int i;
    if(n <=2)
        return 1;
    for(i=2;i <= sqrt(n);i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    unsigned long long int n,i,j;
    cin >> n;
    i = n-1;
    j= n-(n-1);
    while(i > 2)
    {
        if(isPrime(i) == 0 && isPrime(j) == 0)
        {
            cout << i << " " << j;
            return 0;
        }
        i--;
        j++;
    }
    return 0;
}
