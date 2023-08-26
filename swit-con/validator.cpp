#include "testlib.h"

using namespace std;

const int B_MIN = 1'100, B_MAX = 9'900;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int b = inf.readInt(B_MIN, B_MAX, "b");
    inf.readEoln();
    inf.readEof();

    ensuref((b * 10) % 11 == 0 && (b * 10 / 11) % 100 == 0, "a must be a multiple of 100");
}
