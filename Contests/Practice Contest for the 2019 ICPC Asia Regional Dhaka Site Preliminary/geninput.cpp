#include <iostream>
#include <fstream>
using namespace std;

typedef long long ll;

int main()
{
    fstream input;
    input.open("./input.txt",ios::out|ios::trunc);
    input << 1000000 << endl;

    for(int i = 0; i < 1000000; ++i)
        input << 1000000 << endl;
    input.close();
    cout << "done" << endl;
    return 0;
}
