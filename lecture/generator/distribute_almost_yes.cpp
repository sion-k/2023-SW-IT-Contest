#include "testlib.h"

using namespace std;

/*
    모든 강의실 골고루 예약이 도착하는 데이터
    예약은 시간은 절반의 확률로 겹칠 수 있지만, 강의실은 겹치지 않을 수 있다.
*/

const int se_min = 1, se_max = 1'000'000'000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = opt<int>("n");
    int m = opt<int>("m");

    vector<int> t = rnd.distinct(m + 1, se_min, se_max);
    sort(t.begin(), t.end());

    // r[i] = i번째 입력에서 등장하는 방 번호
    vector<int> r(m);
    for (int i = 0; i < m; i++) {
        r[i] = rnd.next(1, n);
    }

    // c[r[i]] = i번째 입력에서 등장하는 방 번호가 몇 번 등장하는지 여부
    vector<int> c = rnd.partition(m, m, 0);

    vector<tuple<int, int, int>> a(m);
    for (int i = 0, j = 0; i < m; i++) {
        while (j < m && c[j] == 0) {
            j++;
        }

        int s = t[i];
        int e = rnd.next(s + 1, min(t[i + 1] + t[i + 1] - (s + 1), se_max));
        int k = r[j];

        a[i] = { k, s, e };

        if (j < m) {
            c[j]--;
        }
    }

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; i++) {
        auto [k, s, e] = a[i];

        cout << k << ' ' << s << ' ' << e << '\n';
    }
}
