#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 200'000;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();
    set<int> check;

    vector<int> t=inf.readInts(n,N_MIN,N_MAX);
    inf.readEoln();
    inf.readEof();

    for(int u:t) check.insert(u);
    ensuref(check.size()==n, "array must be permutation");
}
