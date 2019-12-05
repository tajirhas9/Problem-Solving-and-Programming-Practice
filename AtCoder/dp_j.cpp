#include <bits/stdc++.h>
using namespace std;

#define max 305

double p[max][max][max];
double ev[max][max][max];

int main() {

	#ifdef tajir
		freopen("input.txt","r",stdin);
	#else
		//Online Judge
	#endif

	int n;
	
	cin >> n;

	int cnt[4] = { 0 };

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		cnt[x]++;
	}

	p[cnt[1]][cnt[2]][cnt[3]] = 1;

	for(int c = n; c >= 0; --c) {
		for(int b = n; b >= 0; --b) {
			for(int a = n; a >= 0; --a) {
				if(a+b+c > n)	continue;

				int m = a+b+c;

				if(m == 0)	continue;

				double p_waste = (double)(n - m) / n;

				// S = p_waste + p_waste^2 + p_waste^3 + ...
				double ev_waste = p_waste / (1.0 - p_waste) + 1;	// S = r / (1-r) ( + 1 for gettng solution in this very state)

				ev[a][b][c] += ev_waste * p[a][b][c];

				if(a >= 1) {
					double p_go = (double) a / (double) m;
					p[a-1][b][c] += p[a][b][c] * p_go;
					ev[a-1][b][c] += ev[a][b][c] * p_go;
				}
				if(b >= 1) {
					double p_go = (double) b / (double) m;
					p[a+1][b-1][c] += p[a][b][c] * p_go;
					ev[a+1][b-1][c] += ev[a][b][c] * p_go;
				}
				
				if(c >= 1) {
					double p_go = (double) c / (double) m;
					p[a][b+1][c-1] += p[a][b][c] * p_go;
					ev[a][b+1][c-1] += ev[a][b][c] * p_go;
				}
			}
		}
	}

	cout << fixed << setprecision(10) << ev[0][0][0] << endl;

	return 0;
}
