#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 200'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();

    vector<int> p = inf.readInts(n, 1, n, "p");
    inf.readEoln();

    set<int> s(p.begin(), p.end());
    ensuref(s.size() == n, "p must be a permutation of 1..n");

    inf.readEof();
}
