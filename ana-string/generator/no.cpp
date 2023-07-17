#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = rnd.next(0, 1), a, b;
    if (t) a = rnd.next(N_MIN + 1, N_MAX), b = rnd.next(N_MIN, a - 1);
    else a = rnd.next(N_MIN, N_MAX / 2 - 1), b = (2 * a + 1, N_MAX);
    cout << a << " " << b << "\n";
}
