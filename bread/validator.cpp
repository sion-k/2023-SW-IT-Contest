#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100'000;
const int V_MIN = 1, V_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int a = inf.readInt(N_MIN, N_MAX, "a");
    inf.readSpace();
    int b = inf.readInt(N_MIN, N_MAX, "b");
    inf.readSpace();
    int c = inf.readInt(N_MIN, N_MAX, "c");
    inf.readEoln();

    for (int i = 0; i < a; i++) {
        int p = inf.readInt(V_MIN, V_MAX, "p");
        inf.readSpace();
        int q = inf.readInt(V_MIN, V_MAX, "q");
        inf.readEoln();
    }
    inf.readEof();
}