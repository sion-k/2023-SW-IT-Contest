#include "testlib.h"

using namespace std;

const int A_MIN = 2, A_MAX = 100;
const int B_MIN = 1, B_MAX = 100;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int a = inf.readInt(A_MIN, A_MAX, "a");
    inf.readSpace();
    int b = inf.readInt(B_MIN, B_MAX, "b");
    inf.readEoln();

    inf.readEof();
}
