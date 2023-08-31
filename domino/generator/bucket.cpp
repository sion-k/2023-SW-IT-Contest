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

    int wall = (int)sqrt(n);
    int cnt = 0;
    long long sum = 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = rnd.next(AI_MIN, AI_MAX);
        cnt++;
        sum += a[i];

        if (cnt == wall) {
            a[i] = min(sum + 1, 1'000'000'000LL);
            cnt = 0;
            sum = 0;

            AI_MIN = min(a[i] + 1, 1'000'000'000);
            AI_MAX = min(AI_MIN + wall, 1'000'000'000);
        }
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
