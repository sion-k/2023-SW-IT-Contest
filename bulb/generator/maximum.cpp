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

    int n = 100'000;

    char c = argv[1][0];
    string s = string(n, c);

    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < 2 - (i % 2); j++) {
            change(s, i);
        }
    }

    cout << n << '\n';
    cout << s << '\n';
}
