#include <bits/stdc++.h>
using namespace std;
char s[312345],p[312345];
int pi[3123435],n,m;
void prefixFunction() {
	int j = 0 , i = 1;
	while(i < m) {						
		if(p[i] == p[j]) {
			pi[i] = ++j;
			++i;
		}
		else {
			if(j == 0) {
				pi[i] = 0;
				++i;
			}
			else
				j = pi[j-1];
		}
	}
}

int kmp() {	
	
	prefixFunction();
	
	int i = 0 , j = 0;
	int cnt = 0;
	while(i < n) {
		if(s[i] == p[j]) {
			++i;
			++j;
		}
		if(j == m) {
		
			cnt++;
			j = pi[j-1];		

//			return 1;		
		}
		if(s[i] != p[j]) {
			if(j == 0)
				++i;
			else
				j = pi[j-1];
		}
	}
//	return false;
	return cnt;	
}

int main() {
//	freopen("input.txt","r",stdin);
	p[0] = '.' , p[1] = '.';
	p[2] = '\0';
	int q;
	scanf("%d %d",&n,&q);
	scanf(" %s",s);
	n = strlen(s) , m = 2;
	while(q--) {
		int x;
		char c;
		scanf(" %d %c",&x,&c);
		s[x-1] = c;
		cout << kmp() << endl;
	}
}