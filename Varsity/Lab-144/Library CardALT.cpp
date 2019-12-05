#include <bits/stdc++.h>
#include <map>
using namespace std;
#define pi 		pair<string,string>
#define pii		pair<pi,int>
using namespace std;
class card
{
	string title,author;
	int copies;
	public:
	void store(string t,string a)
	{
		title = t;
		author = a;
		copies++;
	}
	void show()
	{
			cout << "Title : " << title << endl;
			cout << "Author : " << author << endl;
			cout << "Copies : " << copies << endl;
	}
};
map <card,int> m;
int main()
{
	card card1;
	string title,author;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> title >> author;
		card1.store(title,author);
		if(m[card1] >= 1)
		{
			cout << "Already exists" << endl;
		}
		else
		{
			m.insert(card1);
		}
		card1.show();
	}
	return 0;
}
