#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n>=1&&n<=4)			cout << "few" << endl;
	else if(n>=5&&n<=9)		cout << "several" << endl;
	else if(n>=1&&n<=19)	cout << "pack" << endl;
	else if(n>=1&&n<=49)	cout << "lots" << endl;
	else if(n>=1&&n<=99)	cout << "horde" << endl;
	else if(n>=1&&n<=249)	cout << "throng" << endl;
	else if(n>=1&&n<=499)	cout << "swarm" << endl;
	else if(n>=1&&n<=999)	cout << "zounds" << endl;
	else 					cout << "legion" << endl;
	return 0;
}
