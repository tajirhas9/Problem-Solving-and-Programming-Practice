class PairProduct {
public:
	vector <int> findPair(int n, int a0, int step, long long p){
		long long arr[1000];

		arr[0] = a0;
		for(int i = 1; i < n; ++i)
			arr[i] = arr[i-1] + step;
		vector < int > res;
		for(int i = 0; i < n; ++i) {
			if(p % a[i] != )	continue;
			if(binary_search(arr,arr+n, p / a[i])) {
				res.push_back(i);
				res.push_back(j);
				return res;
			}
		}
		return res;
	}
};