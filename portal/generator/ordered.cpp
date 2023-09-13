#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 200'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int g = atoi(argv[2]);

    int n = rnd.next(N_MIN, N_MAX);
    int p[n];
    for (int i = 0; i < n; i++) p[i] = i + 1;

    if (g == -1) reverse(p, p + n);

    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << p[i];
        if (i < n - 1) cout << ' ';
    }

    cout << '\n';
}
