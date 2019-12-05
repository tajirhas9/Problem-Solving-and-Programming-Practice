class SuffixArray {
	string s;
	int n,alphabet,k;

	vector < int > sorted_shifts,eqc;

	vector < int > sort_cyclic_shifts() {
		vector < int > p(n) , c(n) , cnt(max(alphabet , n) , 0);

		for (int i = 0; i < n; i++)
	        cnt[s[i]]++;
	    for (int i = 1; i < alphabet; i++)
	        cnt[i] += cnt[i-1];
	    for (int i = 0; i < n; i++)
	        p[--cnt[s[i]]] = i;
	    c[p[0]] = 0;
	    int classes = 1;
	    for (int i = 1; i < n; i++) {
	        if (s[p[i]] != s[p[i-1]])
	            classes++;
	        c[p[i]] = classes - 1;
	    }
	    vector<int> pn(n), cn(n);
	    for (int h = 0; (1 << h) < n; ++h) {
	    	k = h;
	        for (int i = 0; i < n; i++) {
	            pn[i] = p[i] - (1 << h);
	            if (pn[i] < 0)
	                pn[i] += n;
	        }
	        fill(cnt.begin(), cnt.begin() + classes, 0);
	        for (int i = 0; i < n; i++)
	            cnt[c[pn[i]]]++;
	        for (int i = 1; i < classes; i++)
	            cnt[i] += cnt[i-1];
	        for (int i = n-1; i >= 0; i--)
	            p[--cnt[c[pn[i]]]] = pn[i];
	        cn[p[0]] = 0;
	        classes = 1;
	        for (int i = 1; i < n; i++) {
	            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
	            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
	            if (cur != prev)
	                ++classes;
	            cn[p[i]] = classes - 1;
	        }
	        c.swap(cn);
	    }
	    eqc = c;
/*
	    for(vi :: iterator it = eqc.begin(); it != eqc.end(); ++it) {
	    	if(*it == (n-1)) {
	    		eqc.erase(it);
	    		break;
	    	}
	    }*/
	    return p;
	}

	//for comparing two substrings one starting at i and another starting at j
	int compare(int i, int j) {
		int l = n;
	    pair<int, int> a = mp(eqc[i], eqc[(i+l-(1 << k))%n]);
	    pair<int, int> b = mp(eqc[j], eqc[(j+l-(1 << k))%n]);
	    return a == b ? 0 : a < b ? -1 : 1;
	}

public:
	SuffixArray(string ss) : s(ss) {
		s += '$';
		n = s.size();
		alphabet = 256;

		sorted_shifts = sort_cyclic_shifts();
		sorted_shifts.erase(sorted_shifts.begin());
	}

	vector < int > get_sorted_shifts() {
		return sorted_shifts;
	}

	vector < int > getC() {
		return eqc;
	}

};