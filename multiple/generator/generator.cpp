#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 10;
const int M_MIN = 1, M_MAX = 100;
const int K_MIN = 2, K_MAX = 1'000;
const int AI_MIN = 0, AI_MAX = 9;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n, m, k;
    bool zeroleading;
    if (argc > 5) {
        n = atoi(argv[2]);
        if (n == -1) n = rnd.next(N_MIN, N_MAX);

        m = atoi(argv[3]);
        if (m == -1) m = rnd.next(M_MIN, M_MAX);

        k = atoi(argv[4]);
        if (k == -1) k = rnd.next(K_MIN, K_MAX);

        int f = atoi(argv[5]);
        if (f == 0) zeroleading = false;
        else zeroleading = true;
    } else {
        n = rnd.next(N_MIN, N_MAX);
        m = rnd.next(M_MIN, M_MAX);
        k = rnd.next(K_MIN, K_MAX);
        zeroleading = false;
    }

    set<int> a;
    if (zeroleading) a.insert(0);
    while (a.size() < n) {
        a.insert(rnd.next(AI_MIN, AI_MAX));
    }

    cout << n << ' ' << m << ' ' << k << '\n';
    for (int p : a) {
        cout << p;
        if (--n > 0) cout << ' ';
    }
    cout << '\n';
}
