#include "testlib.h"

using namespace std;

const int N_MIN = 1, N_MAX = 200'000;
const int M_MIN = 1, M_MAX = 200'000;
const int SE_MIN = 1, SE_MAX = 1'000'000'000;

bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    int k1 = get<0>(a), s1 = get<1>(a), e1 = get<2>(a);
    int k2 = get<0>(b), s2 = get<1>(b), e2 = get<2>(b);

    return s1 < s2;
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(N_MIN, N_MAX, "n");
    inf.readSpace();
    int m = inf.readInt(M_MIN, M_MAX, "m");
    inf.readEoln();

    vector<tuple<int, int, int>> a(m);
    for (int i = 0; i < m; i++) {
        int k = inf.readInt(1, n, format("k[%d]", i));
        inf.readSpace();
        int s = inf.readInt(SE_MIN, SE_MAX, format("s[%d]", i));
        inf.readSpace();
        int e = inf.readInt(SE_MIN, SE_MAX, format("e[%d]", i));
        inf.readEoln();

        ensuref(s < e, "s[%d]는 e[%d]보다 작아야 합니다.", i, i);

        a[i] = { k, s, e };
    }

    vector<tuple<int, int, int>> b = a;
    sort(b.begin(), b.end(), compare);

    ensuref(a == b, "예약은 s를 기준으로 오름차순으로 주어져야 합니다.");

    set<int> start;
    for (int i = 0; i < m; i++) {
        int s = get<1>(a[i]);
        start.insert(s);
    }

    ensuref(start.size() == m, "s가 같은 예약은 없어야 합니다.");

    inf.readEof();
}
