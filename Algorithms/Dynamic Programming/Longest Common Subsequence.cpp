class LongestCommonSubsequence {

private:
	vector < vector < int > > dp;
	vector < int > indicesA , indicesB;
	string a,b,s;
	int n,m;

	void genString() {
		
		s += '\0';
		
		int i = n-1 , j = m-1;
		
		while(i != 0 && j != 0) {
			if(dp[i][j] == dp[i-1][j])
				--i;
			else if(dp[i][j] == dp[i][j-1])
				--j;
			else {
				s += a[i];
				--i , --j;
				indicesA.pb(i);
				indicesB.pb(j);
			}
		}
		reverse(all(s));
		sort(all(indicesA));
		sort(all(indicesB));
	}

public:

	LongestCommonSubsequence(string s, string p) {
		
		if(s.size() < p.size())
			swap(s,p);
		
		a = " " + s , b = " " + p;
	
		n = a.size() , m = b.size();

		dp.resize(n);

		for(int i = 0; i < n; ++i)
			dp[i].resize(m,0);

		//Generating LCS

		for(int i = 1; i < n; ++i) {
			for(int j = 1; j < m; ++j) {
				if(a[i] == b[j])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}
		}
		genString();
	}
	string getString() {
		return s;
	}
	int getLength() {
		return dp[n-1][m-1];
	}

	string getA() {
		return a;
	}

	string getB() {
		return b;
	}

	vector < int > getPositionsOfFirstString() {
		return indicesA;
	}

	vector < int > getPositionsOfSecondString() {
		return indicesB;
	}

};
