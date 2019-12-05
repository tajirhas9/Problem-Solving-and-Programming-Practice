#include<bits/stdc++.h>
using namespace std;

#define all(c)	c.begin(),c.end()
#define pb		push_back

int main()
{
	
	
	setbuf(stdout, NULL);

	vector < int > vis(15,0);

	int n,m;

	vector < int > valid;

	vector < int > nums = {0,1,2,3,4,5,6,7,8,9};

	for(int i = 0; i <= 9; ++i) {

		if(valid.size() == 4)
			break;
		char s[5];

		s[0] = i+'0';
		s[4] = '\0';

		int j = 0;

		while(j <= 9) {
			if(j == i) {
				++j;
				continue;
			}
			int x = j , y = (j+1)%10, z = (j+2)%10;

			while(y == x || y == i || y == z)
				y = (y+1)%10;
			while(z == x || z == i || z == y)
				z = (z+1)%10;

			s[1] = x+'0';
			s[2] = y+'0';
			s[3] = z+'0';
			
			printf("%s\n",s);

			scanf("%d %d", &n,&m);

			if(n == 4 && m == 0)
				return 0;

			if(n == 0 && m == 0)
				break;

			if(n == 1 && m == 0) {
				valid.pb(i);
				break;
			}
			else if(n == 0 && m == 1) {
				valid.pb(i);
				break;
			}

			++j;
//			dbg(valid);
		}

	}

	sort(all(valid));
	

	int num = 0;

	char s[5];

	for(int j = 0; j < 4; ++j)
		s[j] = (valid[j]+'0');

	s[4] = '\0';

	printf("%s\n", s);

	scanf("%d %d",&n,&m);

	if(n == 4 && m == 0)
		return 0;

	while(next_permutation(all(valid))) {

		for(int j = 0; j < 4; ++j)
			s[j] = (valid[j]+'0');
		s[4] = '\0';

		printf("%s\n", s);

		scanf("%d %d",&n,&m);

		if(n == 4 && m == 0)
			break;
	}

	return 0;
}






//?
