#include "testlib.h"

using namespace std;

int N_MIN = 2, N_MAX = 100;
int AI_MIN = 1, AI_MAX = 100;

vector<int> __partition(int n, int sum) {
    vector<int> a = rnd.partition<int>(n, sum);

    multiset<int> s(a.begin(), a.end());

    while (*(s.rbegin()) > AI_MAX) {
        int max = *(s.rbegin());
        int min = *(s.begin());

        s.erase(s.find(max));
        s.insert(max - 1);

        s.erase(s.begin());
        s.insert(min + 1);
    }

    a = vector<int>(s.begin(), s.end());
    shuffle(a.begin(), a.end());

    return a;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc >= 4 && strcmp(argv[1], "n") == 0) {
        if (strcmp(argv[2], "?") != 0) {
            N_MIN = atoi(argv[2]);
        }
        if (strcmp(argv[3], "?") != 0) {
            N_MAX = atoi(argv[3]);
        }
    }

    if (argc >= 7 && strcmp(argv[4], "a") == 0) {
        if (strcmp(argv[5], "?") != 0) {
            AI_MIN = atoi(argv[5]);
        }
        if (strcmp(argv[6], "?") != 0) {
            AI_MAX = atoi(argv[6]);
        }
    } else {
        AI_MIN = 1;
        AI_MAX = 100;
    }

    int n = rnd.next(N_MIN, N_MAX);
    int sum = n * rnd.wnext(AI_MIN, AI_MAX, -1);

    vector<int> a = __partition(n, sum);
    vector<int> b = __partition(n, sum);

    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1];
    }
}
