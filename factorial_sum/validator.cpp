#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 1'0000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int a = inf.readInt(N_MIN, N_MAX, "a");
    inf.readSpace();
    int b = inf.readInt(a, N_MAX, "b");
    inf.readEoln();
    inf.readEof();
}
