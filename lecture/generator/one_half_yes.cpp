#include "testlib.h"

using namespace std;

/*
    하나의 강의실에 모든 예약이 도착하는 데이터
    예약은 절반의 확률로 겹칠 수 있다.
*/
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n_min = opt<int>("n_min"), n_max = opt<int>("n_max");
    int m_min = opt<int>("m_min"), m_max = opt<int>("m_max");
    int se_min = opt<int>("se_min"), se_max = opt<int>("se_max");

    int n = rnd.next(n_min, n_max);
    int m = rnd.next(m_min, m_max);
    int k = rnd.next(1, n);

    vector<int> t = rnd.distinct(m + 1, se_min, se_max);
    sort(t.begin(), t.end());

    vector<tuple<int, int, int>> a(m);
    for (int i = 0; i < m; i++) {
        int s = t[i];
        int e = rnd.next(s + 1, min(t[i + 1] + t[i + 1] - (s + 1), se_max));

        a[i] = { k, s, e };
    }

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; i++) {
        int k = get<0>(a[i]), s = get<1>(a[i]), e = get<2>(a[i]);
        cout << k << ' ' << s << ' ' << e << '\n';
    }
}
