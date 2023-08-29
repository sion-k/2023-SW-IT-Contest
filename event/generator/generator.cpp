#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 100'000;
const int AB_MIN = 1, AB_MAX = 100'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n;
    if (argc >= 3 && strcmp(argv[1], "n") == 0 && strcmp(argv[2], "?") != 0) {
        n = atoi(argv[2]);
    } else {
        n = rnd.next(N_MIN, N_MAX);
    }

    int a;
    if (argc >= 5 && strcmp(argv[3], "a") == 0 && strcmp(argv[4], "?") != 0) {
        a = atoi(argv[4]);
    } else {
        a = rnd.next(AB_MIN, n - 1);
    }
    int b = n - a;

    int PQ_MIN, PQ_MAX;
    if (argc >= 8 && strcmp(argv[5], "pq") == 0) {
        if (strcmp(argv[6], "?") != 0) {
            PQ_MIN = atoi(argv[6]);
        } else {
            PQ_MIN = 1;
        }
        if (strcmp(argv[7], "?") != 0) {
            PQ_MAX = atoi(argv[7]);
        } else {
            PQ_MAX = 1'000'000'000;
        }
    } else {
        PQ_MIN = 1;
        PQ_MAX = 1'000'000'000;
    }

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        p[i] = rnd.next(PQ_MIN, PQ_MAX);
        q[i] = rnd.next(PQ_MIN, PQ_MAX);
    }

    cout << n << ' ' << a << ' ' << b << '\n';
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ' << q[i] << '\n';
    }
}
