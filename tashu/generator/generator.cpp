#include "testlib.h"

using namespace std;

const int N_MIN = 2, N_MAX = 100;
const int AI_MIN = 1, AI_MAX = 100;
const int BI_MIN = 1, BI_MAX = 100;

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
