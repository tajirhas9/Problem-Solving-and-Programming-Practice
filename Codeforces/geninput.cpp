#include <iostream>
#include <fstream>
using namespace std;

typedef long long ll;

int main()
{
    fstream input;
    input.open("./input.txt",ios::out|ios::trunc);
    input << 100 << " " << 100 << endl;

    for(int i = 0; i < 100; ++i) {
    	for(int j = 0; j < 100; ++j) {
    		input << '.';
    	}
    	input << endl;
    }
    input.close();
    cout << "done" << endl;
    return 0;
}
