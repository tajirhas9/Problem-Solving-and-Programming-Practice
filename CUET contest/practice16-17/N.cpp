#include<bits/stdc++.h> /*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
	optimize();

	int T;
    string s;
    int n , size , x;
    cin >> T;
 
    for (int kase = 1;kase <= T; kase++) {
        cin >> size;
        cin >> n;
       
        deque <int> q;
        cout << "Case " << kase << ":" << endl;

        for (int i = 0; i < n; i++) {
            cin >> s;
 
            if(s == "pushLeft" || s == "pushRight") {
                cin >> x;
                if(q.size() == size) {
                    cout << "The queue is full" << endl;
                }
                else {
                    if(s == "pushLeft") {
                        cout << "Pushed in left: " << x << endl;
                        q.push_front(x);
                    }
                    if(s == "pushRight"){
                        cout << "Pushed in right: " << x << endl;
                        q.push_back(x);
                    }
                }
 
            }
 
            else {
                if(q.size() == 0) {
                    cout << "The queue is empty" << endl;
                }
 
                else {
                    if(s == "popLeft") {
                        cout << "Popped from left: " << q.front() << endl;
                        q.pop_front();
                    }
                    if(s == "popRight"){
                        cout << "Popped from right: " << q.back() << endl;
                        q.pop_back();
                    }
                }
            }
        } 
    }
	
	return 0;
}






//?
