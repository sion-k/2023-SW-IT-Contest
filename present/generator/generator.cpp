#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 5'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n");
    cout << n << '\n';
}
