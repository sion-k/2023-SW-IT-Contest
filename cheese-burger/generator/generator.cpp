#include "testlib.h"

using namespace std;

const int A_MIN = 2, A_MAX = 100;
const int B_MIN = 1, B_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int a, b;
    if (argc >= 3) {
        a = atoi(argv[1]), b = atoi(argv[2]);
    } else {
        a = rnd.next(A_MIN, A_MAX), b = rnd.next(B_MIN, B_MAX);
    }

    cout << a << " " << b << "\n";
}
