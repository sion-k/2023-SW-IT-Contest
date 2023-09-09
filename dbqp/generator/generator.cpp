#include "testlib.h"

using namespace std;

const int D_MIN = 1, D_MAX = 2;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N_MIN, N_MAX;
    if (argc >= 4 && strcmp(argv[1], "n") == 0) {
        if (strcmp(argv[2], "?") != 0) {
            N_MIN = atoi(argv[2]);
        }

        if (strcmp(argv[3], "?") != 0) {
            N_MAX = atoi(argv[3]);
        }
    } else {
        N_MIN = 1;
        N_MAX = 10;
    }

    int n = rnd.next(N_MIN, N_MAX);
    int d = rnd.next(D_MIN, D_MAX);

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = rnd.next(format("[dbqp]{%d}", n));
    }

    cout << n << ' ' << d << '\n';
    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
}
