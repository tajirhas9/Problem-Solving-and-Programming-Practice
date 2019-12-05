#include <bits/stdc++.h>
#include <queue>
using namespace std;
priority_queue <int> q;
int main()
{
	q.push(7);
	q.push(3);
	q.push(4);
	cout << q.top() << endl;
	int temp;
	temp = q.top();
	q.pop();
	temp--;
	q.push(temp);
	cout << q.top() << endl;
}
