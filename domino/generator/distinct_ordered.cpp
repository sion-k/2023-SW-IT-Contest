#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N_MIN, N_MAX;
    if (argc >= 4 && strcmp(argv[1], "n") == 0) {
        if (strcmp(argv[2], "?") != 0) {
            N_MIN = atoi(argv[2]);
        } else {
            N_MIN = 1;
        }
        if (strcmp(argv[3], "?") != 0) {
            N_MAX = atoi(argv[3]);
        } else {
            N_MAX = 200'000;
        }
    } else {
        N_MIN = 1;
        N_MAX = 200'000;
    }

    int n = rnd.next(N_MIN, N_MAX);

    int AI_MIN, AI_MAX;
    if (argc >= 7 && strcmp(argv[4], "a") == 0) {
        if (strcmp(argv[5], "?") != 0) {
            AI_MIN = atoi(argv[5]);
        } else {
            AI_MIN = 1;
        }

        if (strcmp(argv[6], "?") != 0) {
            AI_MAX = atoi(argv[6]);
        } else {
            AI_MAX = 1'000'000'000;
        }
    } else {
        AI_MIN = 1;
        AI_MAX = 1'000'000'000;
    }

    int d;
    if (argc >= 8 && strcmp(argv[7], "d") == 0 && strcmp(argv[8], "?") != 0) {
        d = atoi(argv[8]);
    } else {
        rnd.next(1, 2);
    }

    vector<int> a = rnd.distinct(n, AI_MIN, AI_MAX);

    if (d == 1) {
        sort(a.begin(), a.end());
    } else if (d == 2) {
        sort(a.begin(), a.end(), greater<int>());
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
