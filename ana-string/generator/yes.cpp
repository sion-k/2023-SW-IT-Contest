#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int a = rnd.next(N_MIN, N_MAX / 2), b = rnd.next(a + 1, 2 * a);
    cout << a << " " << b << "\n";
}
