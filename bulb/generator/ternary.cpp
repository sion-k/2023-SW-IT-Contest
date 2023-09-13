#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int x = atoi(argv[1]);

    string s;
    while (x > 0) {
        s.push_back("RGB"[x % 3]);
        x /= 3;
    }

    if (s.empty()) {
        s.push_back('R');
    }

    reverse(s.begin(), s.end());

    cout << s.size() << '\n';
    cout << s << '\n';
}
