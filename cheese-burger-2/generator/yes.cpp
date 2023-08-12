#include "testlib.h"

using namespace std;

const int A_MIN = 2, A_MAX = 100;
const int B_MIN = 1, B_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int b = rnd.next(B_MIN, B_MAX / 2);
    int a = rnd.next(b + 1, 2 * b);

    cout << a << " " << b << "\n";
}
