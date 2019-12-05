#include<bits/stdc++.h> 
using namespace std;

int trie[2000001][3];
bool finish[2000001];
int nxt = 1;
char s[600001];

void add(char *s,int n) {
	int node = 0;

	for(int i = 0; i < n; ++i) {
		if(trie[node][s[i]-'a'] == 0)
			node = trie[node][s[i]-'a'] = nxt++;
		else
			node = trie[node][s[i]-'a'];
	}
	finish[nxt-1] = true;
}

bool find(char *s,int n,bool avail,int idx,int node) {
	if(idx >= n)	{
		if(avail && finish[node] == 1)
			return true;
		return false;
	}
	
	for(int i = 0; i < 3; ++i) {
		if(trie[node][i] != 0) {
			if(i+'a' == s[idx]) {
				if(find(s,n,avail,idx+1,trie[node][i] ))
					return true;
			}
			else if(!avail) {
				if(find(s,n,true,idx+1,trie[node][i] ))
					return true;
			}
		}
	}
	return false;
}

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	
	int n,m;

	cin >> n >> m;

	for(int i = 0; i < n; ++i) {
		cin >> s;
		add(s,strlen(s));
	}
	
	while(m--) {
		cin >> s;

		if(find(s,strlen(s),0,0,0) )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}






//?
