#include <bits/stdc++.h>
using namespace std;
struct time
{
    int hh,mm,ss,ms;
    time() {
        hh = 0 , mm = 0 , ss = 0 , ms = 0;
    }
    bool operator+=(time t)
    {
        int t1,t2;
        ms += t.ms;
        ss += t.ss;
        if(ms > 1000)
        {
            ms %= 1000;
            ss++;

        }
        if(ss > 60)
        {
            mm += (ss/60);
            ss %= 60;
        }
        if(mm > 60)
        {
            hh += (mm/60);
            mm %= 60;
        }
        if(ms < 0)
        {
            ss += (ms / 1000);
            ms %= 1000;
            ms += 1000;
        }
        if(ss < 0)
        {
            mm += (ss / 60);
            ss %= 60;
            ss += 60;
        }
        if(mm < 0) {
            hh += (mm / 60);
            mm %= 60;
            mm += 60;
        }
    }
    void print() {
    cout << hh << ":" << mm << ":" << ss << "," << ms;
}
} times[1000] , zeroes,add;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);

    vector < int > serials;
    int sz;
    int num;
    vector < string > text;
    while(scanf("%d",&num) != (int)'#')
    {
        printf("%d\n",num);
        if(num == (int)'#')  break;
        serials.push_back(num);
        int i = sz++;
        int j = sz++;
        scanf(" %d:%d:%d,%d --> %d:%d:%d,%d", &times[i].hh , &times[i].mm , &times[i].ss , &times[i].ms , &times[j].hh , &times[j].mm, &times[j].ss, &times[j].ms);
        string s;
        cin >> s;
        text.push_back(s);
    }

    int inc;
    cin >> inc;
    add.ms += inc % 1000;
    add.ss += (inc / 1000);

    sz = text.size();

    for(int i = 0 , j = 0; j < sz; i += 2 , j++) {
        times[i] += add;
        times[i+1] += add;
        cout << serials[j] << endl;
        times[i].print();
        cout << " --> ";
        times[i+1].print();
        cout << text[j] << endl << endl;
    }


    return 0;
}
