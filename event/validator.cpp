#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 100'000;
const int AB_MIN = 1, AB_MAX = 100'000;
const int PQ_MIN = 1, PQ_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readSpace();
    int a = inf.readInt(AB_MIN, n - 1, "a");
    inf.readSpace();
    int b = inf.readInt(AB_MIN, n - 1, "b");
    inf.readEoln();

    ensuref(a + b == n, format("a + b = n이어야 합니다. 그러나 a + b = %d이고 n = %d입니다.", a + b, n).c_str());

    for (int i = 0; i < n; i++) {
        int p_i = inf.readInt(PQ_MIN, PQ_MAX, format("p[%d]", i + 1).c_str());
        inf.readSpace();
        int q_i = inf.readInt(PQ_MIN, PQ_MAX, format("q[%d]", i + 1).c_str());
        inf.readEoln();
    }

    inf.readEof();
}
