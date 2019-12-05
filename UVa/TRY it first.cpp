#include <iostream>
using namespace std;
int main()
{
    string s1;
    int i=1;
    while(1)
    {
        cin >> s1;
        if(s1 == "Hajj")
            cout << "Case " << i << ": Hajj-e-Akbar\n";
        else if(s1 == "Umrah")
            cout << "Case " << i << ": Hajj-e-Asghar\n";
        else if(s1 == "*")
            return 0;
        i++;
    }
    return 0;
}
