#include "testlib.h"

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) (int)((x).size())

using namespace std;

const int AI_MIN = 1, AI_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // m, m, 2m, 4m, 8m, ... 
    long long m = rnd.next(1, 100);
    vector<long long> a;
    a.push_back(m);

    while (m <= AI_MAX) {
        a.push_back(m);
        m *= 2;
    }

    int n = SIZE(a);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
