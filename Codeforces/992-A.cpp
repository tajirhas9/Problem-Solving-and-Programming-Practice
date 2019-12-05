#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	set < int > s;
	int n,x;
	
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		if(x != 0) {
			s.insert(x);
		}
	}

	cout << s.size() << endl;

	return 0;
}






//?
