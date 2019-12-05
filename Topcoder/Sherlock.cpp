#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class Sherlock {
public:
	string isItHim(string firstName, string lastName) {
		string actual1 = "BENEDICT";
		string actual2 =  "CUMBERBATCH";
		vector < bool > vis1(30,false);
		vector < bool > vis2(30,false);
		
		for(int i = 0; i < actual1.size(); ++i)
			vis1[actual1[i]-'A'] = true;
			
		for(int i = 0; i < actual2.size(); ++i)
			vis2[actual2[i] - 'A'] = true;
		int cnt1 = 0;
		int cnt2 = 0;
		
		for(int i = 0; i < firstName.size(); ++i)
			cnt1 += (vis1[firstName[i]-'A'] == true);
		for(int i = 0; i < lastName.size(); ++i)
			cnt2 += (vis2[lastName[i] - 'A'] == true);
		
		string yes = "It is him";
		string no = "It is someone else";
		
		if(cnt1 >= 3 && cnt2 >= 5 && firstName.size() >= 7 && lastName.size() >= 7 && firstName[0] == 'B' && lastName[0] == 'C')
			return yes;
		else
			return no;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	Sherlock *obj;
	string answer;
	obj = new Sherlock();
	clock_t startTime = clock();
	answer = obj->isItHim(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	string p0;
	string p1;
	string p2;
	
	{
	// ----- test 0 -----
	p0 = "BENEDICT";
	p1 = "CUMBERBATCH";
	p2 = "It is him";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "BENADRYL";
	p1 = "CUCUMBERPATCH";
	p2 = "It is him";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "HARSHIT";
	p1 = "MEHTA";
	p2 = "It is someone else";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "BATAXXAT";
	p1 = "CURMUDGEON";
	p2 = "It is him";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "BENEDI";
	p1 = "CUMBER";
	p2 = "It is someone else";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "BAXAXAXY";
	p1 = "CENTRIFUGAL";
	p2 = "It is someone else";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "BUMBLESHACK";
	p1 = "CRUMPLEHORN";
	p2 = "It is him";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
