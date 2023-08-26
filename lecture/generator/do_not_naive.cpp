#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = 200'000;
    int m = 200'000;

    int r=rnd.next(1,n);

    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= m; i++) {
        cout << r << ' ' << i << ' ' << i+1 << '\n';
    }
}
