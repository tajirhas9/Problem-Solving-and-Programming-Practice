#include <bits/stdc++.h>
#include <map>
using namespace std;
#define pi 		pair<string,string>
#define pii		pair<pi,int>
class card
{
	string title,author;
	int copies;
	public:
	void store(string t,string a,int c)
	{
		title = t;
		author = a;
		copies = c;
	}
	void store(void)
	{
		cin >> title >> author >> copies;
	}
	void show()
	{
			cout << "Title : " << title << endl;
			cout << "Author : " << author << endl;
			cout << "Copies : " << copies << endl;
	}
};
int main()
{
	card card1;
	string title,author;
	int copies,i=0,t;
	cin >> t;
	while(++i<=t)
	{
		if(i==1)
		{
			cin >> title >> author >> copies;
			card1.store(title,author,copies);
		}
		else
			card1.store();
		card1.show();
	}
	return 0;
}
