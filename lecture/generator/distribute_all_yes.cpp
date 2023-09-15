#include "testlib.h"

using namespace std;

/*
    서로 다른 강의실에 예약이 도착하는 데이터
*/

const int N_MIN = 1, N_MAX = 200'000;
const int SE_MIN = 1, SE_MAX = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n"), m = opt<int>("m");

    vector<int> t = rnd.distinct(m + 1, SE_MIN, SE_MAX);
    sort(t.begin(), t.end());

    vector<int> k = rnd.distinct(m, 1, n);

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; i++) {
        int s = t[i], e = t[i + 1];

        cout << k[i] << ' ' << s << ' ' << e << '\n';
    }
}
