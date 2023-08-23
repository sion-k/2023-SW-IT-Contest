#include "testlib.h"

using namespace std;

const int N = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int g = atoi(argv[2]);
    int r = rnd.next(2, g);
    int p = rnd.next(1, r - 1), q = r - p;

    cout << r << " " << p << " " << q << "\n";

    for (int i = 0; i < r; i++) {
        int x = rnd.next(1, N);
        cout << x << " " << x << "\n";
    }
}