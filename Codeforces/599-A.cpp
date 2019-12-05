#include <iostream>
#include <cstdio>
using namespace std;
double ab,bc,ca,go,come,s1,s2,s3,s4;
int main()
{
	cin >> ab >> bc >> ca;
	s1 = ab+bc+bc+ab;
	s2 = ab+bc+ca;
	s3 = ca+bc+bc+ca;
	s4 = ab+ab+ca+ca;
	printf("%.0lf\n",min(s1,min(s2,min(s3,s4))));
	return 0;
}
