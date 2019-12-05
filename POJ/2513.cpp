#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

//typedefs

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;
#define pb push_back
//#define pb emplace_back
#define F first
#define S second
#define mp make_pair

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int left_trie[5000000][26],left_finish[5000000];
int right_trie[5000000][26],right_finish[5000000];
int left_nxt = 1,right_nxt = 1;

void addL(string s) {
	int node = 0;
	for(int i = 0; s[i] != '\0'; ++i) {
		if(left_trie[node][s[i]-'a'] == 0)
			node = left_trie[node][s[i]-'a'] = left_nxt++;
		else
			node = left_trie[node][s[i]-'a'];
	}
	left_finish[left_nxt-1]++;
}

bool findL(string s) {
	int idx = 0;

	for(int i = 0; i < s.size(); ++i) {
		if(left_trie[idx][s[i]-'a'] == 0)
			return false;
		else
			idx = left_trie[idx][s[i]-'a'];
	}
//	cout << s << " " << left_finish[idx] << endl;
	if(left_finish[idx] == 0)	return false;
	left_finish[idx]--;
	return ((left_finish[idx]+1)>0);		//if finding word
	//return true;			//if finding prefix
}

void addR(string s) {
	int node = 0;
	for(int i = 0; s[i] != '\0'; ++i) {
		if(right_trie[node][s[i]-'a'] == 0)
			node = right_trie[node][s[i]-'a'] = right_nxt++;
		else
			node = right_trie[node][s[i]-'a'];
	}
	right_finish[right_nxt-1]++;
}

bool findR(string s) {
	int idx = 0;

	for(int i = 0; i < s.size(); ++i) {
		if(right_trie[idx][s[i]-'a'] == 0)
			return false;
		else
			idx = right_trie[idx][s[i]-'a'];
	}
	if(right_finish[idx] == 0)	return false;
	right_finish[idx]--;
	return ((right_finish[idx]+1)>0);		//if finding word
	//return true;			//if finding prefix
}


int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();
	

	string a,b;
	vector < string > left , right;

	while((cin>>a>>b)) {
		left.pb(a) , right.pb(b);
		addL(a);
		addL(b);
	//	addR(b);
	}

	int N = left.size();

	for(int i = 0; i < N && N > 1; ++i) {

	//	if(findR(left[i]))	continue;
		
		if(!findL(right[i]) && !findL(left[i]) ) {
		//	cout << left[i] << " " << right[i] << endl;
			cout << "Impossible" << endl;
			return 0;
		}
	}

	cout << "Possible" << endl;
	
	return 0;
}






//?
