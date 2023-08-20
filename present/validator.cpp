#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 5'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();

    inf.readEof();
}
