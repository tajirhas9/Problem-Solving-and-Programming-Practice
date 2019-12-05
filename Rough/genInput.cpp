#include <iostream>
#include <fstream>
using namespace std;
#define rep(i,a,b)	for(i=a;i<=b;i++)
typedef long long ll;
int main()
{
    fstream input;
    input.open("../input.txt",ios::out|ios::trunc);
    input << 3 << " " << 2 << endl;
    input << 3 << endl;
    input << 1 << " " << 1 << endl;
    input << 3 << " " << 2 << endl;
    input << 1 << " " << 3 << endl;
    input.close();
    cout << "done" << endl;
    return 0;
}
