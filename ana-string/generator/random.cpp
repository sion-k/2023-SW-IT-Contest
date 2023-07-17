#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int a = rnd.next(N_MIN, N_MAX), b = rnd.next(N_MIN, N_MAX);
    cout << a << " " << b << "\n";
}
