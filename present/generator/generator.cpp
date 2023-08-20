#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 5'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n;

    if (argc >= 3 && atoi(argv[1]) == 1) {
        n = atoi(argv[2]);
    } else {
        n = rnd.next(N_MIN, N_MAX);
    }

    cout << n << "\n";
}
