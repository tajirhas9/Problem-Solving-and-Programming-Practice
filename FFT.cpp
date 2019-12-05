#include <bits/stdc++.h>
#include <complex>
using namespace std;

vector <int> fft (vector <int> coef) {
	int n = coef.size();
	if(n==1)	return coef;
	int half = n/2;
	vector <int> odd, even;
	for(int i=0; i< n; i += 2) {
		even.push_back(coef[i]);
		odd.push_back(coef[i+1]);
	}

	vector<int> evenDft, oddDft;

	evenDft = fft(even);
	oddDft = fft(odd);

	double angle = 2*pi / n;
	complex w(1), step(cos(angle), sin(angle));

	vector<int> res;
	res.resize(n);
	//Initially, w = w0n
	for( int i = 0; i< half; i++ ) {
		double temp = evenDft[i] + w * oddDft[i];
		res[i] = temp;

		temp = evenDft[i] - w * oddDft[i];
		res[i+half] = temp;
		
		w = w*step;
	}
	return res;
}