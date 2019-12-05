#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

/*
*I always need the wrapper program that is idle first. So, checking the top of min_heap is enough.
*No need to iterate over all the available wrappers

*/

int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
	
	int T;
	scanf("%d",&T);
	
	for(int kase = 1; kase <= T; ++kase) {
		
		int n;

		scanf("%d",&n);

		vector < pair < int , int > > a(n);

		for(int i = 0; i < n; ++i)
			scanf("%d %d", &a[i].F , &a[i].S);


		sort(a.begin() , a.end());

		priority_queue < int , vector < int > , greater<int> > q;

		q.push(2e9);

		int res = 0;

		for(int i = 0; i < n; ++i) {
			bool flag = false;

			int top = q.top();

			if(a[i].F <= top) 
				res++;
			else
				q.pop();
			q.push(a[i].S);
		}

	
		printf("Case %d: %d\n",kase, res );
	}
	

	return 0;
}