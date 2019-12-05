#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define F first
#define S second

#define RESET(a,b)	memset(a,b,sizeof(a))

const int inf = 2000000000;

string num,ans;
int total=inf;
map < string , bool > m;
vector < char > dial[10];

int trie[5*50000][26],finish[5*500000];
int nxt = 1;

void init() {
	for(int i = 0; i < 10; ++i)
		dial[i].resize(3);

	dial[0] = {'o' , 'q' , 'z'};
		
	dial[1] = {'i' , 'j'};
		
	dial[2] = {'a','b','c'};
	dial[3] = {'d','e','f'};
		
	dial[4] = {'g','h'};
	dial[5] = {'k','l'};
	dial[6] = {'m','n'};
		
	dial[7] = {'p','r','s'};
	dial[8] = {'t','u','v'};
	dial[9] = {'w','x','y'};

	dial[1].resize(2);
	dial[4].resize(2);
	dial[5].resize(2);
	dial[6].resize(2);

}

void reset() {

	memset(trie,0,sizeof(trie));

	memset(finish,0,sizeof(finish));

	m.clear();

	total = inf;

	nxt = 1;
}

void add(string s) {
	int node = 0;
	for(int i = 0; s[i] != '\0'; ++i) {
		if(trie[node][s[i]-'a'] == 0)
			node = trie[node][s[i]-'a'] = nxt++;
		else
			node = trie[node][s[i]-'a'];
	}
	finish[nxt-1] = 1;
}

bool find(string s) {
	int idx = 0;

	for(int i = 0; i < s.size(); ++i) {
		if(trie[idx][s[i]-'a'] == 0)
			return false;
		else
			idx = trie[idx][s[i]-'a'];
	}
	return true;
}

void solve(int idx, string s[],int tot) {
	
	if(idx == num.size()) {
	
		if(tot == 0 && s[tot].empty())	return;	//if empty string is detected
	
		if(tot < total) {		// s[0] = reality , s[1] = our (tot = 2) < s[0] = real , s[1] = it , s[2] = your (total = 3)
	
			total = tot;
	
			ans.clear();
	
			for(int i = 1; i <= tot; ++i) {	// s[0] = reality s[1] = our
	
				ans += s[i];
	
				ans += " ";
	
			}
	
			return;
	
		}
	
		return;
	}
	
	string temp;
	
	for(auto n : dial[num[idx]-'0'] ) {
	
		string p = s[tot];
	
		p += n;
	
		temp = s[tot];
	
		if(find(p)) {	//check if this pattern matches any of the prefixes of the given words
	
			if( m[p] ) {	//if it is a complete word, then do two things
							//	1. count it as a complete word and proceed. s[0] = real , s[1] = --fill this index now--
							//	2. don't count it as a complete word. s[0] = real(ity) '() -> alphabets inside bracket are to come next'
				s[tot] = p;
	
				solve(idx+1,s,tot+1);
	
				solve(idx+1,s,tot);
	
			}
	
			else {
	
				s[tot] = p;
	
				solve(idx+1,s,tot);
	
			}
	
			s[tot] = temp;
		}
	
	}
}

int main()
{	
	string s;

	init();
	
	while(cin >> num && num != "-1") {
		int n;
		
		reset();

		cin >> n;

		while(n--) {
			cin >> s;
			m[s] = true;
		}
		
		//add the words to the trie

		for(map < string , bool > :: iterator it = m.begin(); it != m.end(); ++it)
			add(it->F);

		
		ans.clear();
		string p[50000];

//		p[0].clear();

		solve(0,p,1);
		
		if(ans.empty())
			ans = "No solution.";

		cout << ans << endl;

	}
	
	return 0;
}






//?
