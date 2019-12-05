#include <bits/stdc++.h>
using namespace std;

int n,m;

vector < set < int > > hasRidden;

vector < int > q;
vector < int > inFW;

bool complete() {

	for(int i = 0; i < n; ++i) {
		if(hasRidden[i].size() < m)	return false;
	}

	return true;
}

bool vis(int i, int j) {
	return hasRidden[i].find(j) != hasRidden[i].end();
}

void markSeat(int i, int j) {
	hasRidden[i].insert(j);
	return;
}

void getIn(int i, int j) {
	int who = q[i];
	q.erase(q.begin()+i);		//get out from the queue
	inFW[j] = who;				// get in the FW
	return;
}

void getOut(int i, int j) {
	markSeat(i , j);
	inFW[j] = -1;

	if(hasRidden[i].size() == m)	return;

	q.push_back(i);
	return;
}

int main() {
	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//online submission
	#endif
		
	int T;
	scanf("%d",&T);
	
	for(int kase = 1; kase <= T; ++kase) {
		
		scanf("%d %d", &n,&m);
		int t = 5;
		int now = 0;

		hasRidden.resize(n);
		inFW.assign(m,-1);
		q = vector<int>();

		for(int i = 0; i < n; ++i)
			q.push_back(i);

		while(!complete()) {

			//get out
			if(inFW[now] != -1) {
				getOut(inFW[now],now);
			}

			//get in
			int nextRider = -1;
			for(int i = 0; i < q.size(); ++i) {
				if(!vis(q[i] , now)) {
					nextRider = i;
					break;
				}
			}
			if(nextRider != -1) 
				getIn(nextRider,now);

			if(complete())
				break;
			now = (now+1)%m;
			t += 5;
		}
	
		printf("Case %d: %d\n",kase, t);

		hasRidden.clear();
		q.clear();
		inFW.clear();
	}
	

	return 0;
}