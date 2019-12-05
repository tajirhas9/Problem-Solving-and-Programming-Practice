#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    long long num = 1200000000000;
    num--;
    inf.readLong(1,num,"a");
    inf.readEoln();
    inf.readEof();
}