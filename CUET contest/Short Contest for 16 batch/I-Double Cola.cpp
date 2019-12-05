#include <bits/stdc++.h>
#include <queue>
using namespace std;
//queue <string> q;
int main()
{
	int t,doubling=1;
	string names[] = {"Sheldon","Leonard","Penny","Rajesh","Howard"};
    cin >> t;
    while (doubling*5<t)
    {
        t -= doubling*5;
        doubling *= 2;
    }
    cout << names[(--t)/doubling] << endl;

	return 0;
}
