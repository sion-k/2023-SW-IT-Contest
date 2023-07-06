#include "testlib.h"

using namespace std;

const int AB_MIN = 1, AB_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc >= 3) {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);

        cout << a << " " << b << "\n";
    } else {
        int a = rnd.next(AB_MIN, AB_MAX);
        int b = rnd.next(AB_MIN, AB_MAX);

        cout << a << " " << b << "\n";
    }
}
