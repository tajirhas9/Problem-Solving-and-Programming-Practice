#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    long long num = 1000000000;
    inf.readLong(1,num,"a");
    inf.readEoln();
    inf.readEof();
}