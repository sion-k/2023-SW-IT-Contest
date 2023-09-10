#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 1'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int a = rnd.next(N_MIN, N_MAX);
    int b = rnd.next(a, N_MAX);
    cout << a << " " << b << "\n";
}
