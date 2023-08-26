#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 200'000;
const int M_MIN = 1, M_MAX = 200'000;
const int SE_MIN = 1, SE_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int nv=atoi(argv[2]);
    int sev= atoi(argv[3]);

    int n = rnd.next(N_MIN,nv);
    int m = 200'000;

    vector<int> start = rnd.distinct(m, sev, SE_MAX - 1);
    sort(start.begin(), start.end());

    vector<tuple<int, int, int>> a(m);
    for (int i = 0; i < m; i++) {
        int k = rnd.next(1, n);
        int s = start[i];
        int e = rnd.next(s + 1, SE_MAX);

        a[i] = { k, s, e };
    }

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; i++) {
        int k = get<0>(a[i]), s = get<1>(a[i]), e = get<2>(a[i]);
        cout << k << ' ' << s << ' ' << e << '\n';
    }
}
