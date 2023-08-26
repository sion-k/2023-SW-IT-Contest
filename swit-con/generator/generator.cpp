#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int a = atoi(argv[1]);
    int b = a + a / 10;

    cout << b << '\n';
}
