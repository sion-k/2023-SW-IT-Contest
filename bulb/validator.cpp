#include "testlib.h"

using namespace std;

const int N_MIN = 3, N_MAX = 100'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();

    string s = inf.readLine("[RGB]{" + to_string(n) + "}", "s");
    inf.readEof();
}
