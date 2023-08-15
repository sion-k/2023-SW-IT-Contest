#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 100;
const int AI_MIN = 1, AI_MAX = 100;
const int BI_MIN = 1, BI_MAX = 100;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(N_MIN, N_MAX);
    cout << n << "\n";

    int sum = n * rnd.next(AI_MIN, AI_MAX);
}
