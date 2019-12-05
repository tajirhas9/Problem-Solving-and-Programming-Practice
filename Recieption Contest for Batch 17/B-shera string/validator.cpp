#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 100, "testCount");
    inf.readEoln();
    inf.readWord();
    inf.readEof();
}