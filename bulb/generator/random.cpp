#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N_MIN = 3, N_MAX = 100'000;
    if (argc >= 4 && strcmp(argv[1], "n") == 0) {
        if (strcmp(argv[2], "?") != 0) {
            N_MIN = atoi(argv[2]);
        }

        if (strcmp(argv[3], "?") != 0) {
            N_MAX = atoi(argv[3]);
        }
    }

    int n = rnd.next(N_MIN, N_MAX);
    string s = rnd.next(format("[RGB]{%d}", n));

    cout << n << '\n';
    cout << s << '\n';
}
