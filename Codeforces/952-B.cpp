#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	ll q,i=0,no=0;
	while(i<10) {
		s.clear();
		printf("%lld\n", i++);
		fflush(stdout);
		getline(cin, s);
		if((s.compare("worse") == 0) || 
			(s.compare("terrible") == 0) ||
			(s.compare("go die in a hole")) == 0 ||
			(s.compare("are you serious?")) == 0 ||
			(s.compare("no way") == 0) || 
			(s.compare("don't even") == 0) ) {
				
				printf("grumpy\n");
				fflush(stdout);
				return 0;
		}
	}
	printf("normal\n");
	fflush(stdout);
 	return 0;
}




//?
