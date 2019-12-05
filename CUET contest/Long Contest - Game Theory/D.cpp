#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {

        string s;
        cin >> s;

        multiset < int > Set;

        for(int i = 0; i < s.size(); ++i)
            Set.insert(s[i]-'0');

        int sum = 0;

        for(auto x : Set)
            sum += x;

        multiset < int > :: iterator it;

        bool win = false;
        bool moveDone = true;

        while(moveDone) {
            if(Set.size() == 1) {
                win = !win;
                break;
            }
            moveDone = false;
            for(it = Set.begin(); it != Set.end(); ++it) {
                int val = *it;

                if( (sum - val) % 3 == 0) {
                    win = !win;
                    sum -= val;
                    Set.erase(it);
                    moveDone = true;
                    break;

                }
            }
        }

        cout << "Case " << kase << ": ";
        cout << (win ? "S" : "T") << endl;
    }
    return 0;
}
