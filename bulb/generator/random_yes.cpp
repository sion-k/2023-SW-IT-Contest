#include "testlib.h"

using namespace std;

const int N_MIN = 3, N_MAX = 100'000;
const vector<char> COLOR = { 'R', 'G', 'B' };

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

    int n = rnd.next(N_MIN, N_MAX);
    char c = rnd.any(COLOR.begin(), COLOR.end());

    string s(n, c);
    for (int i = 1; i < n - 1; i++) {
        int k = rnd.next(-2, 2);
        for (int j = 0; j < k; j++) {
            change(s, i);
        }
    }

    cout << n << "\n";
    cout << s << "\n";
}
