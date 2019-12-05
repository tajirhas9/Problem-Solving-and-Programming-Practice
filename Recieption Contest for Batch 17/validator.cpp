#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int testCount = inf.readInt(1, 10, "testCount");
    inf.readEoln();
    
    for (int i = 0; i < testCount; i++) {
        int n = inf.readInt(1, 40000, "n");
        inf.readSpace();
        int m = inf.readInt(1, min(15000,n*(n-1)) , "m");
        inf.readEoln();

        for(int i = 0; i < m; ++i) {
            inf.readInt(1, n, "u");
            inf.readSpace();
            inf.readInt(1,n,"v");
            inf.readSpace();
            inf.readInt(1,1000000000,"w");
            inf.readEoln();
        }
        int q = inf.readInt(1,100000,"q");
        inf.readEoln();
        for(int i = 0;i < q; ++i){
            inf.readInt(1,1000000000,"c");
            inf.readEoln();
        }
    }

    inf.readEof();
}