#include <iostream>
using namespace std;

int main() {

	string s;

	getline(cin , s);

	string month = s.substr(0,3);

	if(month == "oct") {
		printf("The zodiac sign is Libra\n");
	}
	else {
		printf("The zodiac sign is not libra\n");
	}

	return 0;
}