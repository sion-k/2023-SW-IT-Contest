#include "testlib.h"

using namespace std;

const int N_MIN = 3, N_MAX = 100'000;
const vector<char> COLOR = { 'R', 'G', 'B' };

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(N_MIN, N_MAX);

    string s(n, 'R');
    for (int i = 0; i < n; i++) {
        s[i] = rnd.any(COLOR.begin(), COLOR.end());
    }

    cout << n << "\n";
    cout << s << "\n";
}
