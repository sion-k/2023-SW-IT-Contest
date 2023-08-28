#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 10;
const int D_MIN = 1, D_MAX = 2;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n;

    if (argc >= 3 && atoi(argv[1]) == 1) {
        n = atoi(argv[2]);
    } else {
        n = rnd.next(N_MIN, N_MAX);
    }

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
