#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N_MIN = 2, N_MAX = 100;
const int AI_MIN = 1, AI_MAX = 100;
const int BI_MIN = 1, BI_MAX = 100;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readEoln();

    vector<int> a = inf.readInts(n, AI_MIN, AI_MAX, "a");
    inf.readEoln();

    vector<int> b = inf.readInts(n, BI_MIN, BI_MAX, "b");
    inf.readEoln();

    inf.readEof();

    int sum_a = accumulate(a.begin(), a.end(), 0);
    int sum_b = accumulate(b.begin(), b.end(), 0);

    ensuref(sum_a == sum_b, "The sum of a must be equal to the sum of b");
}
