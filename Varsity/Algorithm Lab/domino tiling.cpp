#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
typedef pair < int , int > pii;

int board[10000][10000];
int N,cnt,ex,ey;
map < int , int > M;
bool flag = false;

void reset(int a = rand()%N, int b = rand()%N) {
	cnt = 0;
	int x = a;
	int y = b;
	for(int i = 0 ;i <= N; ++i)
		for(int j = 0; j <= N; ++j) {
			if(i == x && j == y)
				board[i][j] = -1;
			else
				board[i][j] = 0;
		}
	ex = x , ey = y;
}


void printBoard(int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cout << setw(5) << board[i][j] << " ";
		cout << endl;
	}
}

void printBoard2(int n,int l) {
	cout << endl << endl;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(board[i][j] <= l)
				cout << setw(5) << board[i][j] << " ";
			else
				cout << setw(5) << "X" << " ";
		}
		cout << endl;
	}
}

void fill(pii a, pii b, pii c) {
	++cnt;
	board[a.first][a.second] = cnt;
	board[b.first][b.second] = cnt;
	board[c.first][c.second] = cnt;
}

void solve(int sz , int x1, int y1 , int x2 , int y2, int defX , int defY ) {
	if(sz==2) {
		cnt++;
		for(int i = x1; i <= x2; ++i) {
			for(int j = y1; j <= y2; ++j) {
				if(board[i][j] == 0) {
					board[i][j] = cnt;
				}
			}
		}

		if(flag)
			printBoard(N);
		return;
	}
	else {
		int posX,posY;
		for(int i = x1; i <= x2; ++i) {
			for(int j = y1; j <= y2; ++j) {
				if(board[i][j] != 0)
					posX = i , posY = j;
			}
		}

		pair < int , int > p1,p2,p3,p4;

		p1 = mp( x1+sz/2 -1, y1+sz/2 -1);
		p2 = mp(x1+sz/2 , y1+sz/2-1);
		p3 = mp(x1+sz/2 -1 , y1+sz/2);
		p4 = mp(x1+sz/2, y1+sz/2);

		if(posX < x1+sz/2 && posY < y1+sz/2) {
			fill(p2,p3,p4);
			if(flag) {
				printBoard(N);
			}
			solve(sz/2 , x1 , y1 , x1+sz/2-1 , y1+sz/2-1,p1.first,p1.second);
			solve(sz/2 , x1 , y1+sz/2 , x1+sz/2-1 , y2,p2.first,p2.second);
			solve(sz/2 , x1+sz/2 , y1 , x2 , y1+sz/2-1,p3.first,p3.second);
			solve(sz/2 , x1+sz/2 , y1+sz/2 , x2,y2,p4.first,p4.second);
		}

		else if(posX < x1+sz/2 && posY >= y1+sz/2) {
			fill(p1,p2,p4);
			if(flag)
				printBoard(N);
			solve(sz/2 , x1 , y1 , x1+sz/2-1 , y1+sz/2-1,p1.first,p1.second);
			solve(sz/2 , x1 , y1+sz/2 , x1+sz/2-1 , y2,p2.first,p2.second);
			solve(sz/2 , x1+sz/2 , y1 , x2 , y1+sz/2-1,p3.first,p3.second);
			solve(sz/2 , x1+sz/2 , y1+sz/2 , x2,y2,p4.first,p4.second);
		}
		else if(posX >= x1+sz/2 && posY >= y1+sz/2) {
			fill(p1,p2,p3);
			if(flag)
				printBoard(N);
			solve(sz/2 , x1 , y1 , x1+sz/2-1 , y1+sz/2-1,p1.first,p1.second);
			solve(sz/2 , x1 , y1+sz/2 , x1+sz/2-1 , y2,p2.first,p2.second);
			solve(sz/2 , x1+sz/2 , y1 , x2 , y1+sz/2-1,p3.first,p3.second);
			solve(sz/2 , x1+sz/2 , y1+sz/2 , x2,y2,p4.first,p4.second);
		}
		else {
			fill(p1,p3,p4);
			if(flag)
				printBoard(N);
			solve(sz/2 , x1 , y1 , x1+sz/2-1 , y1+sz/2-1,p1.first,p1.second);
			solve(sz/2 , x1 , y1+sz/2 , x1+sz/2-1 , y2,p2.first,p2.second);
			solve(sz/2 , x1+sz/2 , y1 , x2 , y1+sz/2-1,p3.first,p3.second);
			solve(sz/2 , x1+sz/2 , y1+sz/2 , x2,y2,p4.first,p4.second);
		}
	}
}

void solve(int sz) {
	solve(sz , 0 , 0 , N- 1, N-1 , ex, ey );
}

int main() {
	srand(time(0));
	for(int i = 2; i < 500; i *= 2) {
		N = i;
		reset();
		solve(N);
		M[cnt] = N;
	}
	int l;
	while(cin >> l) {
		int x,y;
		cin >> x >> y;
		--x , --y;
		int sz;
		for(auto it = M.begin(); it != M.end(); ++it) {
			if(it->first >= l) {
				sz = it->second;
				break;
			}
		}
		cout << "board size : " << sz << " * " << sz << endl;
		N = sz;
		reset(x,y);
		solve(sz);

		printBoard2(sz,l);
	}


	return 0;
}