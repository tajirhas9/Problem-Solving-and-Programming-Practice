#include <bits/stdc++.h>
using namespace std;
int row,col;
class matrix
{
	vector<int> mat;
	public:
	void setMatrix(void);
	void setMatrix(vector<int>m);
	void clearMatrix(void);
	vector<int> getMatrix(void);
	void display(void);
	matrix operator+(matrix m1);
};
void matrix::setMatrix(void)
{
	int x,i;
	for(i=0;i<row*col;i++)
	{	cin >> x;
		mat.push_back(x);
	}
}
void matrix::setMatrix(vector<int>m)
{
	int i;
	for(i=0;i<row*col;i++)
	{
		mat.push_back(m[i]);
	}
}
vector<int> matrix::getMatrix(void)
{
	return mat;
}
void matrix::display(void)
{
	int i;
	for(i=0;i<row*col;i++)
	{
		cout << mat[i] << " ";
		if((i+1)%col==0 && i != 0)	cout << endl;
	}
}
void matrix::clearMatrix(void)
{
	mat.erase(mat.begin(),mat.begin()+row*col);
}
matrix matrix::operator+(matrix m2)
{
	int i,x;
	matrix m6;
	vector<int> m3,m4,m5;
	m5 = (*this).getMatrix();
	m3 = m2.getMatrix();
	for(i=0;i<row*col;i++)
	{
		x = m5[i]+m3[i];
		m4.push_back(x);
	}
	m6.setMatrix(m4);
	return m6;
}
matrix m1,m2,m3;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> row >> col;
		m1.setMatrix();
		m2.setMatrix();
		m3 = m1+m2;
		m3.display();
		m1.clearMatrix();
		m2.clearMatrix();
	}
	return 0;
}
