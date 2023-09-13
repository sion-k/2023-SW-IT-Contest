#include "testlib.h"

using namespace std;

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
    string s = string(n, c);

    for (int i = 1; i < n - 1; i++) {
        int k = rnd.next(-2, 2);
        for (int j = 0; j < k; j++) {
            change(s, i);
        }
    }

    cout << n << '\n';
    cout << s << '\n';
}
