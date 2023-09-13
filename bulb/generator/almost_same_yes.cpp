#include "testlib.h"

using namespace std;

/*
* 거의 한가지 색으로 빛나는 전구를 의미하는 문자열을 생성합니다.
*
* 사용법:
*   almost_same n n_min n_max [c] [d] [p]
*
*   n_min: 문자열의 최소 길이
*   n_max: 문자열의 최대 길이
*   c: 대부분의 색
*   d: 일부 다른 색
*   p: 다른 색깔 개수(3개씩 연속)
*
*/

void change(string& s, int i) {
    for (int j = i - 1; j <= i + 1; j++) {
        if (s[j] == 'R') {
            s[j] = 'G';
        } else if (s[j] == 'G') {
            s[j] = 'B';
        } else {
            s[j] = 'R';
        }
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N_MIN = 3, N_MAX = 100'000;
    if (argc >= 4 && strcmp(argv[1], "n") == 0) {
        if (strcmp(argv[2], "?") != 0) {
            N_MIN = atoi(argv[2]);
        }

        if (strcmp(argv[3], "?") != 0) {
            N_MAX = atoi(argv[3]);
        }
    }

    int n = rnd.next(N_MIN, N_MAX);

    char c = rnd.next("[RGB]")[0];
    if (argc >= 5 && strcmp(argv[4], "?") != 0) {
        c = argv[4][0];
    }

    char d = rnd.next("[RGB]")[0];
    if (argc >= 6 && strcmp(argv[5], "?") != 0) {
        d = argv[5][0];
    }

    int p = rnd.next(0, n - 2);
    if (argc >= 7 && strcmp(argv[6], "?") != 0) {
        p = atoi(argv[6]);
    }

    string s(n, c);

    vector<int> t = rnd.distinct(p, n - 2);
    for (int x : t) {
        change(s, x + 1);
    }

    cout << n << '\n';
    cout << s << '\n';
}
