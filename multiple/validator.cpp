#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 10;
const int M_MIN = 1, M_MAX = 100;
const int K_MIN = 2, K_MAX = 1'000;
const int AI_MIN = 0, AI_MAX = 9;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readSpace();
    int m = inf.readInt(M_MIN, M_MAX, "m");
    inf.readSpace();
    int k = inf.readInt(K_MIN, K_MAX, "k");
    inf.readEoln();

    vector<int> a = inf.readInts(n, AI_MIN, AI_MAX, "a");
    inf.readEoln();

    inf.readEof();

    vector<int> b = a;
    sort(b.begin(), b.end());

    ensuref(a == b, "준혁이가 고른 숫자는 오름차순으로 주어져야 합니다.");

    set<int> s(a.begin(), a.end());

    ensuref(s.size() == n, "준혁이가 고른 숫자는 중복되지 않아야 합니다.");
}
