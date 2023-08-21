#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 10;
const int D_MIN = 1, D_MAX = 4;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readSpace();
    int d = inf.readInt(D_MIN, D_MAX, "d");
    inf.readEoln();

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = inf.readLine(format("[dbqp]{%d}", n), format("s[%d]", i + 1));
    }

    inf.readEof();
}
