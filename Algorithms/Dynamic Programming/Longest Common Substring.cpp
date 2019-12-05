class LongestCommonSubstring {

private:
	vector < vector < int > > dp;
	vector < int > indicesA , indicesB;
	string a,b,s;
	int n,m,maxLength,maxLengthPositionX,maxLengthPositionY;

	void genString() {
		
		s += '\0';
		
		int i = maxLengthPositionX , j = maxLengthPositionY;
		
		while(1) {
			s += a[i];
			--i , --j;
			indicesA.pb(i);
			indicesB.pb(j);
			
			if(dp[i][j] == 0)
				break;
		}
		reverse(all(s));
		sort(all(indicesA));
		sort(all(indicesB));
	}

	void genMaxLength() {
		maxLength = 0;

		for(int i = 1; i < n; ++i) {
			for(int j = 1; j < m; ++j) {
				if(dp[i][j] > maxLength) {
					maxLength = dp[i][j];
					maxLengthPositionX = i;
					maxLengthPositionY = j;
				}
			}
		}

	}

public:

	LongestCommonSubstring(string s, string p) {
		
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
					dp[i][j] = 0;
			}
		}
		genMaxLength();
		genString();
	}
	string getString() {
		return s;
	}
	int getLength() {
		return maxLength;
	}

	vector < int > getPositionsOfFirstString() {
		return indicesA;
	}

	vector < int > getPositionsOfSecondString() {
		return indicesB;
	}

};
