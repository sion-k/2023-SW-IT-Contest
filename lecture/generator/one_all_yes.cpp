#include "testlib.h"

using namespace std;

/*
    하나의 강의실에 모든 예약이 도착하는 데이터
    모든 예약은 겹치지 않는다.
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

    cout << n << ' ' << m << '\n';
    for (int i = 0; i < m; i++) {
        cout << k << ' ' << t[i] << ' ' << t[i + 1] << '\n';
    }
}
