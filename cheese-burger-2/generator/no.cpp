#include "testlib.h"

using namespace std;

const int A_MIN = 2, A_MAX = 100;
const int B_MIN = 1, B_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int a, b;

    if (rnd.next(0, 1)) {
        a = rnd.next(A_MIN + 2, A_MAX);
        b = rnd.next(B_MIN, a - 2);
    } else {
        b = rnd.next(B_MIN, B_MAX / 2 - 1);
        a = rnd.next(2 * b + 1, A_MAX);
    }

    cout << a << " " << b << "\n";
}
